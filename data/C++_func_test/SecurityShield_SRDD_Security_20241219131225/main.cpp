int main(int argc, char *argv[]) {
    cout << "Initializing SecurityShield..." << endl;
    vector<IoTDevice> devices;
    SecurityScanner scanner;
    EncryptionManager encryptionManager;
    RemoteAccessManager remoteAccessManager;
    int i;
    i = 0;
    for (; ; ) {
        if (!(5 > i)) {
            break;
        }
        IoTDevice device("Device_" + to_string(i + 1), "192.168.0." + to_string(i + 1));
        devices.push_back(device);
        cout << "Registered: " << device.getDeviceID() << " with IP: " << device.getIPAddress() << endl;
        i++;
    }
    cout << "Starting real-time monitoring..." << endl;
    i = 0;
    for (; ; ) {
        if (!(10 > i)) {
            break;
        }
        for (vector<IoTDevice>::iterator it = devices.begin(); it != devices.end(); it++) {
            scanner.scanDevice(*it);
            encryptionManager.encryptData(it->getDeviceID(), "SampleData");
        }
        remoteAccessManager.authenticateUser("admin", "password123");
        Utilities::logEvent("Monitoring cycle " + to_string(i + 1) + " completed.");
        i++;
    }
    cout << "SecurityShield terminated." << endl;
    return 0;
}