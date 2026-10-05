void AnomalyDetector::predictAnomalies(const vector<vector<double>>& data) {
    size_t i, j;
    for (i = 0; i < data.size(); i++) {
        double mean = calculateMean(data[i]);
        double stddev = calculateStandardDeviation(data[i], mean);
        for (j = 0; j < data[i].size(); j++) {
            if (abs(data[i][j] - mean) > 2 * stddev) {
                cout << "Anomaly detected: " << data[i][j] << endl;
            }
        }
    }
}