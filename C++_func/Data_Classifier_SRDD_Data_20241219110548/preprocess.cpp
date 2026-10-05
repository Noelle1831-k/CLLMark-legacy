vector<vector<double>> DataPreprocessor::preprocess(const vector<vector<double>>& data) {
    vector<vector<double>> processedData = data;
    for (size_t i = 0; i < processedData[0].size(); ++i) {
        double maxVal = -INFINITY;
        double minVal = INFINITY;
        for (size_t j = 0; j < processedData.size(); ++j) {
            maxVal = max(maxVal, processedData[j][i]);
            minVal = min(minVal, processedData[j][i]);
        }
        for (size_t j = 0; j < processedData.size(); ++j) {
            processedData[j][i] = (processedData[j][i] - minVal) / (maxVal - minVal);
        }
    }
    return processedData;
}