vector<string> NetworkMonitor::monitor() {
    vector<string> networkData;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 5);
    int packetCount = dis(gen);
    for (int i = 0; i < packetCount; i++) {
        networkData.push_back("Packet" + to_string(i + 1));
    }
    return networkData;
}