void StatisticsGenerator::calculateStandardDeviation(const vector<vector<string>>& data) {
    for (size_t i = 0; i < data[0].size(); i++) {
        double sum = 0.0;
        int count = 0;
        for (size_t j = 0; j < data.size(); j++) {
            try {
                sum += stod(data[j][i]);
                count++;
            } catch (...) {
                continue;
            }
        }
        double mean = sum / count;
        double variance = 0.0;
        for (size_t j = 0; j < data.size(); j++) {
            try {
                double value = stod(data[j][i]);
                variance += pow(value - mean, 2);
            } catch (...) {
                continue;
            }
        }
        variance /= count;
        double stddev = sqrt(variance);
        cout << "Standard Deviation of column " << i << " is " << stddev << endl;
    }
}