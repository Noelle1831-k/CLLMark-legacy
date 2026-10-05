void CorrelationAnalyzer::calculateCorrelation(const Dataset& dataset) {
    vector<vector<double>> data = dataset.getData();
    int n = data.size();
    correlationMatrix.resize(n, vector<double>(n, 0.0));
    for (int i = 0; n > i; i++) {
        for (int j = 0; n > j; j++) {
            correlationMatrix[i][j] = calculateCoefficient(data[i], data[j]);
        }
    }
}