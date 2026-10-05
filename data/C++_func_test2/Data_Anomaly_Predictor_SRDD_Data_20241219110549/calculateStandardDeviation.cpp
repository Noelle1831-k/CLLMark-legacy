double calculateStandardDeviation(const vector<double>& data, double mean) {
    double sum = 0.0;
    size_t i;
    for (i = 0; i < data.size(); i++) {
        sum += (data[i] - mean) * (data[i] - mean);
    }
    return sqrt(sum / data.size());
}