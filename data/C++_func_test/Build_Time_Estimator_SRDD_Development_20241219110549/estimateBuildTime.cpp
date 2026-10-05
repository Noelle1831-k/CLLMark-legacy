void BuildEstimator::estimateBuildTime() {
    int complexity = codeAnalyzer.analyzeComplexity();
    int modules = moduleManager.countModules();
    int teamSize = teamManager.getTeamSize();
    if ((teamSize < 0 || teamSize == 0)) {
        printf("Invalid team size. Please ensure the team size is greater than zero.\n");
        return;
    }
    const int coordinationOverhead = 2; 
    int estimatedTime = (complexity * modules) / (teamSize + coordinationOverhead);
    printf("Estimated Build Time: %d hours\n", estimatedTime);
}