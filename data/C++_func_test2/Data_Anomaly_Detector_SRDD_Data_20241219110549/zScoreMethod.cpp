vector<int> AnomalyDetector::zScoreMethod(vector<double> data) {
    vector<int> anomalies;
    double mean = computeMean(data);
    double stddev = computeStdDev(data);
    for (size_t i = 0; i < data.size(); i++) {
        double zScore = (data[i] - mean) / stddev;
        if (zScore > 3 || zScore < -3) {
            anomalies.push_back(i);
        }
    }
    return anomalies;
}