double calculateMean(const vector<double>& data) {
    double sum = 0.0;
    size_t i;
    for (i = 0; i < data.size(); i++) {
        sum += data[i];
    }
    return sum / data.size();
}