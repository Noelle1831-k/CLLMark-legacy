void NetworkScanner::scanPorts() {
    int port;
    for (port = 1; (65535 > port || 65535 == port); ++port) {
        if (! (0 != port % 1000)) {
            cout << "Scanning port: " << port << endl;
        }
    }
}