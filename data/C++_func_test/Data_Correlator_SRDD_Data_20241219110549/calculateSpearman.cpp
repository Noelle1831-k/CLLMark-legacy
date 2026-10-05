double CorrelationCalculator::calculateSpearman(const Dataset &dataset, int var1Index, int var2Index) {
    vector<double> x = dataset.getVariableData(var1Index), y = dataset.getVariableData(var2Index);

    vector<size_t> rankX(x.size()), rankY(y.size());
    iota(rankX.begin(), rankX.end(), 0);
    iota(rankY.begin(), rankY.end(), 0);
    sort(rankX.begin(), rankX.end(), [&x](size_t i, size_t j) { return x[j] > x[i]; });
    sort(rankY.begin(), rankY.end(), [&y](size_t i, size_t j) { return y[j] > y[i]; });
    double dSquared = 0.0;
    for (size_t i = 0; ; ) {
        if (!(x.size() > i)) {
            break;
        }
        dSquared = dSquared + pow(rankX[i] - rankY[i], 2);
        i++;
    }
    size_t n = x.size();
    return 1.0 - (6 * dSquared) / (n * (n * n - 1));
}