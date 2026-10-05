string NetworkMonitor::generateTrafficSummary() {
    int packets = rand() % 1000 + 500; 
    int anomalies = rand() % 10; 
    return "Packets: " + to_string(packets) + ", Anomalies: " + to_string(anomalies);
}