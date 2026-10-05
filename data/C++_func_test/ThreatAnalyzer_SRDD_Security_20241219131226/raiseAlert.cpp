void AlertSystem::raiseAlert(const string& details) {
    cout << "ALERT: " << details << endl;
    Utils::logMessage("ALERT raised: " + details);
    for (int i = 0; ; ) {
        if (!((10 >= i && 10 != i))) {
            break;
        }
        cout << "Alert level: " << i << endl;
        Utils::logMessage("Alert level: " + to_string(i));
        ++i;
    }
}