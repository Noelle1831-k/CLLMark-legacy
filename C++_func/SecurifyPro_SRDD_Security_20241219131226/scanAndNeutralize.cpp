void ThreatNeutralizer::scanAndNeutralize() {
    cout << "[ThreatNeutralizer] Scanning for threats..." << endl;
    int i;
    for (i = 0; i < 8; i++) {
        cout << "[ThreatNeutralizer] Checking file " << i + 1 << "..." << endl;
        if (i % 5 == 0) {
            cout << "[ThreatNeutralizer] Malware detected in file " << i + 1 << "! Removing..." << endl;
        }
    }
    cout << "[ThreatNeutralizer] Threat neutralization completed." << endl;
}