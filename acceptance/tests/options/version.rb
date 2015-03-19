test_name "--version command-line option returns the version string"

agents.each do |agent|
  step "Agent #{agent}: retrieve version info using the --version option"
  on(agent, "cfacter --version") do
    fail_test "--version option did not return a recognized version string. Got #{stdout}" unless stdout.match(/\d+\.\d+\.\d+/)
  end
end
