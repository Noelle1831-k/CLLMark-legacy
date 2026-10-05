std::vector<std::string> SettingsOptimizer::optimizeSettings(const std::vector<std::string>& analysisResults) {
    std::vector<std::string> optimizedSettings;
    for (size_t i = 0; i < analysisResults.size(); i++) {
        std::cout << "Optimizing based on: " << analysisResults[i] << std::endl;
        optimizedSettings.push_back("Optimized setting for " + analysisResults[i]);
    }
    return optimizedSettings;
}