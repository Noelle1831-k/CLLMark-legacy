void DataPreprocessor::preprocessData(vector<vector<double>>& data) {
    if (data.empty()) return;
    size_t numFeatures = data[0].size();
    for (size_t i = 0; i < numFeatures; ++i) {
        double minVal = data[0][i];
        double maxVal = data[0][i];
        for (size_t j = 0; j < data.size(); ++j) {
            minVal = min(minVal, data[j][i]);
            maxVal = max(maxVal, data[j][i]);
        }
        for (size_t j = 0; j < data.size(); ++j) {
            data[j][i] = (data[j][i] - minVal) / (maxVal - minVal);
        }
    }
}