test_name "--trace command-line option enables backtraces for custom facts"

unix_content = <<EOM
#!/usr/bin/ruby
Facter.add('custom_fact') do
  setcode do
    non_existent_value
  end
end
EOM

win_content = <<EOM
Facter.add('custom_fact') do
  setcode do
    non_existent_value
  end
end
EOM

agents.each do |agent|
  if agent['platform'] =~ /windows/
    if on(agent, cfacter('kernelmajversion')).stdout.chomp.to_f < 6.0
      custom_dir = 'C:/Documents and Settings/All Users/Application Data/PuppetLabs/facter/custom'
    else
      custom_dir = 'C:/ProgramData/PuppetLabs/facter/custom'
    end
    content = win_content
  else
    custom_dir  = '/opt/puppetlabs/facter/custom'
    content = unix_content
  end

  step "Agent #{agent}: create custom fact directory and executable custom fact"
  on(agent, "mkdir -p '#{custom_dir}'")
  custom_fact = "#{custom_dir}/custom_fact.rb"
  create_remote_file(agent, custom_fact, content)
  on(agent, "chmod +x #{custom_fact}")

  teardown do
    on(agent, "rm -f '#{custom_fact}'")
  end

  step "--trace option should provide a backtrace for a custom fact with errors"
  begin
    on(agent, "FACTERLIB=#{custom_dir} cfacter --trace custom_fact")
  rescue Exception => e
    assert_match(/backtrace:\n\t#{custom_fact}:4:in `block \(2 levels\)/, e.message)
  end
end
