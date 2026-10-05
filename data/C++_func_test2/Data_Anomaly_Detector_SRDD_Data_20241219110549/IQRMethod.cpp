vector<int> AnomalyDetector::IQRMethod(vector<double> data) {
    vector<int> anomalies;
    size_t n = data.size();
    sort(data.begin(), data.end());
    double Q1 = data[n / 4];
    double Q3 = data[3 * n / 4];
    double IQR = Q3 - Q1;
    for (size_t i = 0; i < data.size(); i++) {
        if (data[i] < Q1 - 1.5 * IQR || data[i] > Q3 + 1.5 * IQR) {
            anomalies.push_back(i);
        }
    }
    return anomalies;
}