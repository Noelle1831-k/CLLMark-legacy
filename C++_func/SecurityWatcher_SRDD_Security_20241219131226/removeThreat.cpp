void ThreatHandler::removeThreat(const string &threat) {
    cout << "Removing threat: " << threat << endl;
    quarantinedThreats.erase(remove(quarantinedThreats.begin(), quarantinedThreats.end(), threat), quarantinedThreats.end());
}