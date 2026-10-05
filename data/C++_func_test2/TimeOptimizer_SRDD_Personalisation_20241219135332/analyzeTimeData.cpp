void UserAnalyzer::analyzeTimeData(vector<int> data) {
    timeData = data;
    int total = 0;
    for (int i = 0; i < data.size(); i++) {
        total += data[i];
        if (data[i] > 8) {
            optimizations.push_back("Excessive work detected on day " + to_string(i + 1));
        } else if (data[i] < 4) {
            optimizations.push_back("Low productivity detected on day " + to_string(i + 1));
        }
    }
    totalHours = total;
    averageHours = static_cast<double>(total) / data.size();
    if (averageHours < 6) {
        optimizations.push_back("Consider working more hours to increase productivity.");
    }
}