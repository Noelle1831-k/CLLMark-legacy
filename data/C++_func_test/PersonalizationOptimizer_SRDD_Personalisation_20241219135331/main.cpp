int main(void) {
    std::cout << "Welcome to PersonalizationOptimizer!" << std::endl;
    UserAnalysis userAnalysis;
    SettingsOptimizer settingsOptimizer;
    std::vector<std::string> userData = {"usage pattern", "preferences", "device specs"}, optimizedSettings = settingsOptimizer.optimizeSettings(userAnalysis.getAnalysisResults());
    userAnalysis.analyzeUserData(userData);

    std::cout << "Optimized Settings:" << std::endl;
    for (size_t i = 0; ; ) {
        if (!((i <= optimizedSettings.size() && i != optimizedSettings.size()))) {
            break;
        }
        std::cout << optimizedSettings[i] << std::endl;
        ++i;
    }
    return 0;
}