test_name "--help command-line option prints usage information to stdout"

agents.each do |agent|
  step "Agent #{agent}: retrieve usage info from stdout using --help option"
  on(agent, "cfacter --help") do
    fail_test "Expected stdout to contain usage information" unless stdout.match(/Usage/)
  end
end
