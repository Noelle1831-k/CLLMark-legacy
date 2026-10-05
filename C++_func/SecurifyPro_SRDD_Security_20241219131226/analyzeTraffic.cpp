void NetworkAnalyzer::analyzeTraffic() {
    cout << "[NetworkAnalyzer] Analyzing network traffic..." << endl;
    int i;
    for (i = 0; i < 10; i++) {
        cout << "[NetworkAnalyzer] Checking packet " << i + 1 << "..." << endl;
        if (i % 3 == 0) {
            cout << "[NetworkAnalyzer] Suspicious activity detected in packet " << i + 1 << "!" << endl;
        }
    }
    cout << "[NetworkAnalyzer] Network traffic analysis completed." << endl;
}