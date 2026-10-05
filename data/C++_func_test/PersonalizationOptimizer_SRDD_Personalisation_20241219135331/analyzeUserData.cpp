void UserAnalysis::analyzeUserData(const std::vector<std::string>& userData) {
    for (size_t i = 0; i < userData.size(); i++) {
        std::cout << "Analyzing: " << userData[i] << std::endl;
        analysisResults.push_back("Result for " + userData[i]);
    }
}