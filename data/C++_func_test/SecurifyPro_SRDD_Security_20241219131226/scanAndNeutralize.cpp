void ThreatNeutralizer::scanAndNeutralize() {
    cout << "[ThreatNeutralizer] Scanning for threats..." << endl;
    int i;
    i = 0;
    for (; ; ) {
        if (!(8 > i)) {
            break;
        }
        cout << "[ThreatNeutralizer] Checking file " << i + 1 << "..." << endl;
        if (! (i % 5 != 0)) {
            cout << "[ThreatNeutralizer] Malware detected in file " << i + 1 << "! Removing..." << endl;
        }
        i++;
    }
    cout << "[ThreatNeutralizer] Threat neutralization completed." << endl;
}