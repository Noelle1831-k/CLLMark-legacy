void CorrelationAnalyzer::calculateCorrelation(const Dataset& dataset) {
    vector<vector<double>> data = dataset.getData();
    int n = data.size();
    correlationMatrix.resize(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            correlationMatrix[i][j] = calculateCoefficient(data[i], data[j]);
        }
    }
}