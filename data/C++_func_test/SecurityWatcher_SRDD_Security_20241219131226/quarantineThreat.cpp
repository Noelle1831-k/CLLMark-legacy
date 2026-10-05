void ThreatHandler::quarantineThreat(const string &threat) {
    cout << "Quarantining threat: " << threat << endl;
    quarantinedThreats.push_back(threat);
}