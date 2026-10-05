void AnomalyDetector::applyStatisticalMethods(const vector<vector<double>>& data) {
    for (const auto& row : data) {
        double mean = 0.0;
        for (double value : row) {
            mean = mean + value;
        }
        mean = mean / row.size();
        double variance = 0.0;
        for (double value : row) {
            variance = variance + pow(value - mean, 2);
        }
        variance = variance / row.size();
        double stddev = sqrt(variance);
        for (double value : row) {
            double zScore = (value - mean) / stddev;
            if (abs(zScore) > 3) {
                cout << "Anomaly detected (Z-score): " << value << endl;
            }
        }
    }
}