void ThreatDetector::detectThreat(const string &threat) {
    cout << "Threat detected: " << threat << "\n";
    detectedThreats.push_back(threat);
    logThreat(threat);
}