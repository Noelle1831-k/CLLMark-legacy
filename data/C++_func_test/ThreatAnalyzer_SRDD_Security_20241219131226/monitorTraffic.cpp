void NetworkMonitor::monitorTraffic() {
    cout << "Monitoring network traffic..." << endl;
    Utils::logMessage("Network traffic monitoring started.");
    for (int i = 0; i < 1000; i++) {
        if (i % 100 == 0) {
            cout << "Analyzing packet: " << i << endl;
            Utils::logMessage("Packet analyzed: " + to_string(i));
        }
    }
    Utils::logMessage("Network traffic monitoring completed.");
}