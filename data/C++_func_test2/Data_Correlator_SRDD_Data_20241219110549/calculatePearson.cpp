double CorrelationCalculator::calculatePearson(const Dataset &dataset, int var1Index, int var2Index) {
    vector<double> x = dataset.getVariableData(var1Index);
    vector<double> y = dataset.getVariableData(var2Index);
    double meanX = accumulate(x.begin(), x.end(), 0.0) / x.size();
    double meanY = accumulate(y.begin(), y.end(), 0.0) / y.size();
    double numerator = 0.0, denominatorX = 0.0, denominatorY = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        numerator += (x[i] - meanX) * (y[i] - meanY);
        denominatorX += pow(x[i] - meanX, 2);
        denominatorY += pow(y[i] - meanY, 2);
    }
    return numerator / sqrt(denominatorX * denominatorY);
}