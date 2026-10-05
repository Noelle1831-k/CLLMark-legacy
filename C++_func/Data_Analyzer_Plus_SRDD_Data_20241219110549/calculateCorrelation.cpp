double StatisticsUtils::calculateCorrelation(const std::vector<double>& data1, const std::vector<double>& data2) {
    double mean1 = calculateMean(data1);
    double mean2 = calculateMean(data2);
    double numerator = 0.0;
    double denominator1 = 0.0;
    double denominator2 = 0.0;
    for (size_t i = 0; i < data1.size(); i++) {
        numerator += (data1[i] - mean1) * (data2[i] - mean2);
        denominator1 += pow(data1[i] - mean1, 2);
        denominator2 += pow(data2[i] - mean2, 2);
    }
    return numerator / (sqrt(denominator1) * sqrt(denominator2));
}