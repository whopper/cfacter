test_name "--verbose command-line option prints verbose information to stderr"

agents.each do |agent|
  step "Agent #{agent}: retrieve verbose info from stderr using --verbose option"
  on(agent, "cfacter --verbose") do
    fail_test "Expected stderr to contain verbose (INFO) information" unless stderr.match(/INFO/)
  end
end
