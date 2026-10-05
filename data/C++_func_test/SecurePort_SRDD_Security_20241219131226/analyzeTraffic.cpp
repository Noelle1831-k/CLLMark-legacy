void TrafficAnalyzer::analyzeTraffic() {
    cout << "Analyzing network traffic..." << endl;
    int i;
    for (i = 0; i < 100; i++) {
        if (! (i % 10 != 0)) {
            logSuspiciousActivity();
        }
    }
}