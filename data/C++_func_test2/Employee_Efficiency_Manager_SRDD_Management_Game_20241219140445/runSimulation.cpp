void Simulation::runSimulation() {
    cout << "Running simulation..." << endl;
    teamManager.assignTasksToEmployees();
    teamManager.trackProgress();
    feedback.giveFeedback("Excellent work on completing tasks!");
    teamManager.optimizeProductivity();
    teamManager.displayTeamDetails();
}