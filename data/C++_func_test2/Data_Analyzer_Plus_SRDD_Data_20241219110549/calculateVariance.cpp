double StatisticsUtils::calculateVariance(const std::vector<double>& data) {
    double mean = calculateMean(data);
    double variance = 0.0;
    for (size_t i = 0; i < data.size(); i++) {
        variance += pow(data[i] - mean, 2);
    }
    return variance / data.size();
}