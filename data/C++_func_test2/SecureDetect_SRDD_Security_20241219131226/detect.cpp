bool ThreatDetector::detect(const vector<string>& networkData, const vector<string>& logData, const vector<string>& userData) {
    bool threatDetected = false;
    for (unsigned int i = 0; i < networkData.size(); i++) {
        if (networkData[i].find("Size=1000") != string::npos) {
            threatDetected = true;
            break;
        }
    }
    for (unsigned int i = 0; i < logData.size(); i++) {
        if (logData[i].find("Failed login attempt") != string::npos) {
            threatDetected = true;
            break;
        }
    }
    for (unsigned int i = 0; i < userData.size(); i++) {
        if (userData[i].find("privilege escalation") != string::npos) {
            threatDetected = true;
            break;
        }
    }
    return threatDetected;
}