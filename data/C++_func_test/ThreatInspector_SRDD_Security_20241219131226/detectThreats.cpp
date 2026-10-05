void ThreatDetector::detectThreats(const vector<string>& files) {
    cout << "Detecting threats..." << endl;
    for (size_t i = 0; i < files.size(); ++i) {
        analyzeFile(files[i]);
    }
}