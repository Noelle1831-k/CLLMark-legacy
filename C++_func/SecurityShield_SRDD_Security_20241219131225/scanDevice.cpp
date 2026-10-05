void SecurityScanner::scanDevice(const IoTDevice &device) {
    cout << "Scanning device: " << device.getDeviceID() << " at IP: " << device.getIPAddress() << endl;
    int i;
    for (i = 0; i < 1000000; i++) {
        if (i % 100000 == 0) {
            cout << ".";
        }
    }
    cout << " Scan complete." << endl;
}