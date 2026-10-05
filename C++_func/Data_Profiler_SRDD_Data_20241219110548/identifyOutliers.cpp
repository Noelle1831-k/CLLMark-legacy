void DataAnalyzer::identifyOutliers(const vector<vector<string>>& data) {
    for (size_t i = 0; i < data[0].size(); i++) {
        vector<double> columnData;
        for (size_t j = 0; j < data.size(); j++) {
            try {
                columnData.push_back(stod(data[j][i]));
            } catch (...) {
                continue;
            }
        }
        double mean = 0.0;
        for (size_t k = 0; k < columnData.size(); k++) {
            mean += columnData[k];
        }
        mean /= columnData.size();
        double variance = 0.0;
        for (size_t k = 0; k < columnData.size(); k++) {
            variance += pow(columnData[k] - mean, 2);
        }
        variance /= columnData.size();
        double stddev = sqrt(variance);
        for (size_t k = 0; k < columnData.size(); k++) {
            if (fabs(columnData[k] - mean) > 2 * stddev) {
                cout << "Outlier detected in column " << i << " at row " << k << endl;
            }
        }
    }
}