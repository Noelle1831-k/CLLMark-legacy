int main() {
    std::cout << "Welcome to PersonalizationOptimizer!" << std::endl;
    UserAnalysis userAnalysis;
    SettingsOptimizer settingsOptimizer;
    std::vector<std::string> userData = {"usage pattern", "preferences", "device specs"};
    userAnalysis.analyzeUserData(userData);
    std::vector<std::string> optimizedSettings = settingsOptimizer.optimizeSettings(userAnalysis.getAnalysisResults());
    std::cout << "Optimized Settings:" << std::endl;
    for (size_t i = 0; i < optimizedSettings.size(); i++) {
        std::cout << optimizedSettings[i] << std::endl;
    }
    return 0;
}