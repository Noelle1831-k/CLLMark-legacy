UserAnalyzer* createUserAnalyzer() {
    UserAnalyzer *analyzer = (UserAnalyzer*)malloc(sizeof(UserAnalyzer));
    analyzer->analysisData = 0;
    return analyzer;
}