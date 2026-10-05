void ThreatHandler::handleThreat(const string &threat) {
    cout << "Handling threat: " << threat << endl;
    quarantineThreat(threat);
}