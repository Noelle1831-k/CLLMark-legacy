vector<string> AnalyticsEngine::generateInsights(const vector<vector<int>> &data) {
    vector<string> insights;
    for (size_t i = 0; i < data.size(); ++i) {
        double avg = accumulate(data[i].begin(), data[i].end(), 0.0) / data[i].size();
        double stdDev = Utils::calculateStandardDeviation(data[i]);
        stringstream ss;
        ss << "Room " << i + 1 << " - Average Occupancy: " << avg << ", Std Dev: " << stdDev;
        insights.push_back(ss.str());
    }
    int maxOccupancy = 0;
    int maxRoom = -1;
    for (size_t i = 0; i < data.size(); ++i) {
        int peak = *max_element(data[i].begin(), data[i].end());
        if (peak > maxOccupancy) {
            maxOccupancy = peak;
            maxRoom = i + 1;
        }
    }
    insights.push_back("Room with Highest Peak Occupancy: Room " + to_string(maxRoom));
    return insights;
}