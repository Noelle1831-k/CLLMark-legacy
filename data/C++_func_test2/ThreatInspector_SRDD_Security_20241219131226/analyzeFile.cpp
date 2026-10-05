void ThreatDetector::analyzeFile(const string& file) {
    cout << "Analyzing " << file << " for threats..." << endl;
    detectedThreats.push_back("Threat found in " + file);
}