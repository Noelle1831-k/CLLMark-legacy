bool Monitoring::scanForThreats() {
    cout << "Scanning for threats..." << endl;
    int threatLevel = rand() % 100; 
    if (threatLevel > 50) {
        cout << "Threat detected! Level: " << threatLevel << endl;
        return true;
    }
    cout << "No threats detected." << endl;
    return false;
}