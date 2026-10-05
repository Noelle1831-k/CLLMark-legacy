void BuildEstimator::estimateBuildTime() {
    int complexity = codeAnalyzer.analyzeComplexity();
    int modules = moduleManager.countModules();
    int teamSize = teamManager.getTeamSize();
    if (teamSize <= 0) {
        cout << "Invalid team size. Please ensure the team size is greater than zero." << endl;
        return;
    }
    const int coordinationOverhead = 2; 
    int estimatedTime = (complexity * modules) / (teamSize + coordinationOverhead);
    cout << "Estimated Build Time: " << estimatedTime << " hours" << endl;
}