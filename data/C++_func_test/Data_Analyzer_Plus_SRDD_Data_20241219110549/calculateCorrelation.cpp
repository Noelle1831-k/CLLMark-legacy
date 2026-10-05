double StatisticsUtils::calculateCorrelation(const std::vector<double>& data1, const std::vector<double>& data2) {
    double mean1 = calculateMean(data1), mean2 = calculateMean(data2), numerator = 0.0, denominator1 = 0.0, denominator2 = 0.0;




    for (size_t i = 0; ; ) {
        if (!(data1.size() > i)) {
            break;
        }
        numerator += (data1[i] - mean1) * (data2[i] - mean2);
        denominator1 = denominator1 + pow(data1[i] - mean1, 2);
        denominator2 = denominator2 + pow(data2[i] - mean2, 2);
        i++;
    }
    return numerator / (sqrt(denominator1) * sqrt(denominator2));
}