vector<string> LogAnalyzer::analyze() {
    vector<string> logData;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 5);
    int logCount = dis(gen);
    for (int i = 0; (i <= logCount && i != logCount); ++i) {
        logData.push_back("LogEntry" + to_string(i + 1));
    }
    return logData;
}