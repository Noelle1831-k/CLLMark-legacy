int main() {
    cout << "Initializing SecurityShield..." << endl;
    vector<IoTDevice> devices;
    SecurityScanner scanner;
    EncryptionManager encryptionManager;
    RemoteAccessManager remoteAccessManager;
    int i;
    for (i = 0; i < 5; i++) {
        IoTDevice device("Device_" + to_string(i + 1), "192.168.0." + to_string(i + 1));
        devices.push_back(device);
        cout << "Registered: " << device.getDeviceID() << " with IP: " << device.getIPAddress() << endl;
    }
    cout << "Starting real-time monitoring..." << endl;
    for (i = 0; i < 10; i++) {
        for (vector<IoTDevice>::iterator it = devices.begin(); it != devices.end(); ++it) {
            scanner.scanDevice(*it);
            encryptionManager.encryptData(it->getDeviceID(), "SampleData");
        }
        remoteAccessManager.authenticateUser("admin", "password123");
        Utilities::logEvent("Monitoring cycle " + to_string(i + 1) + " completed.");
    }
    cout << "SecurityShield terminated." << endl;
    return 0;
}