void AlertSystem::raiseAlert(string message) {
    cout << "ALERT: " << message << endl;
    logAlertDetails(message);
}