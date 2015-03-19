test_name "--debug command-line option prints debugging information to stderr"

agents.each do |agent|
  step "Agent #{agent}: retrieve debug info from stderr using --debug option"
  on(agent, "cfacter --debug") do
    fail_test "Expected stderr to contain debugging (DEBUG) information" unless stderr.match(/DEBUG/)
  end
end
