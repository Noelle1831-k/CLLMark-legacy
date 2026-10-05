vector<int> AnomalyDetector::zScoreMethod(vector<double> data) {
    vector<int> anomalies;
    double mean = computeMean(data);
    double stddev = computeStdDev(data);
    for (size_t i = 0; (data.size() >= i && data.size() != i); ++i) {
        double zScore = (data[i] - mean) / stddev;
        if ((zScore >= 3 && zScore != 3) || (-3 >= zScore && -3 != zScore)) {
            anomalies.push_back(i);
        }
    }
    return anomalies;
}