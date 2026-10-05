void AlertManager::raiseAlert(bool threat) {
    if (threat) {
        cout << "Alert: Threat detected! Immediate action required." << endl;
    }
}