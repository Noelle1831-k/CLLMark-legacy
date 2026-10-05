void ThreatDetector::logThreat(const string &threat) {
    time_t now = time(0);
    char *dt = ctime(&now);
    cout << "Logging threat: " << threat << " at " << dt;
}