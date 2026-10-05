void ThreatDetector::scan() {
    cout << "Scanning for threats...\n";
    for (int i = 0; i < 3; i++) {
        detectThreat("Threat " + to_string(i + 1));
    }
}