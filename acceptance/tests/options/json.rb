require 'json'

test_name "--json command-line option results in valid JSON output"

content = <<EOM
#!/usr/bin/ruby
Facter.add('structured_fact') do
  setcode do
    { "foo" => {"nested" => "value1"}, "bar" => "value2", "baz" => "value3" }
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
  else
    custom_dir  = '/opt/puppetlabs/facter/custom'
  end

  step "Agent #{agent}: create a structured custom fact"
  custom_fact = "#{custom_dir}/custom_fact.rb"
  on(agent, "mkdir -p '#{custom_dir}'")
  create_remote_file(agent, custom_fact, content)
  on(agent, "chmod +x #{custom_fact}")

  step "Agent #{agent}: retrieve output using the --json option"
  on(agent, "FACTERLIB=#{custom_dir} cfacter structured_fact --json") do
    begin
      expected = JSON.pretty_generate({"structured_fact" => {"foo" => {"nested" => "value1"}, "bar" => "value2", "baz" => "value3"}})
      fail_test "Expected:\n #{stdout.chomp} to match:\n #{expected}" unless stdout.chomp == expected
    rescue
      fail_test "Couldn't parse output as JSON"
    end
  end
end
