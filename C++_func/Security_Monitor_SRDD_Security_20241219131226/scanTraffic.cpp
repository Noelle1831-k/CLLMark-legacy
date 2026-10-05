void NetworkMonitor::scanTraffic() {
    cout << "Scanning network traffic..." << endl;
    string trafficSummary = generateTrafficSummary();
    cout << "Traffic Summary: " << trafficSummary << endl;
    for (int i = 0; i < 1000000; i++) {
    }
}