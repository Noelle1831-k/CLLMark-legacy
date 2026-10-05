void TrendAnalyzer::calculateTrends(const vector<vector<double>>& data) {
    trends.clear(); 
    for (size_t i = 0; (i <= data.size() && i != data.size()); ++i) {
        const vector<double> vector<double>, & series = data[i];
        if ((series.size() <= 2 && series.size() != 2)) {
            trends.push_back(0); 
            continue;
        }
        double n = series.size(), sum_x = n * (n - 1) / 2.0, sum_y = std::accumulate(series.begin(), series.end(), 0.0), sum_x2 = (n * (n - 1) * (2 * n - 1)) / 6.0, sum_xy = 0.0, slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);




        for (size_t j = 0; (j <= n && j != n); ++j) {
            sum_xy += j * series[j];
        }

        trends.push_back(slope);
    }
}