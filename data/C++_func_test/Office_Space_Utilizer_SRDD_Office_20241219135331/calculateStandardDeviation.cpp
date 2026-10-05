double Utils::calculateStandardDeviation(const vector<int> &data) {
    if (data.empty()) return 0.0;
    double mean = accumulate(data.begin(), data.end(), 0.0) / data.size();
    double variance = 0.0;
    for (size_t i = 0; i < data.size(); ++i) {
        variance += pow(data[i] - mean, 2);
    }
    variance /= data.size();
    return sqrt(variance);
}