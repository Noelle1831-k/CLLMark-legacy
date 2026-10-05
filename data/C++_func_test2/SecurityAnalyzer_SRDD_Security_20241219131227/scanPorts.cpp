void NetworkScanner::scanPorts() {
    int port;
    for (port = 1; port <= 65535; port++) {
        if (port % 1000 == 0) {
            cout << "Scanning port: " << port << endl;
        }
    }
}