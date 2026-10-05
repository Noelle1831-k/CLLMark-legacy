void AnomalyDetector::calculateStatistics(const vector<vector<double>> &data) {
    for (size_t col = 0; col < data[0].size(); col++) {
        double sum = 0, mean = 0, variance = 0;
        for (size_t row = 0; row < data.size(); row++) {
            sum += data[row][col];
        }
        mean = sum / data.size();
        for (size_t row = 0; row < data.size(); row++) {
            variance += pow(data[row][col] - mean, 2);
        }
        variance /= data.size();
        cout << "Column " << col + 1 << ": Mean = " << mean << ", Variance = " << variance << endl;
    }
}