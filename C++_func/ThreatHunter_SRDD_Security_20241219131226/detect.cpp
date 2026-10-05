vector<string> ThreatDetection::detect(const vector<string>& networkData, const vector<string>& logData, const vector<string>& userData) {
    vector<string> threats;
    if (!networkData.empty() && !logData.empty() && !userData.empty()) {
        if (networkData.size() > 2 || logData.size() > 2 || userData.size() > 2) {
            threats.push_back("Threat1");
        }
        if (networkData.size() > 3 && logData.size() > 3) {
            threats.push_back("Threat2");
        }
    }
    return threats;
}