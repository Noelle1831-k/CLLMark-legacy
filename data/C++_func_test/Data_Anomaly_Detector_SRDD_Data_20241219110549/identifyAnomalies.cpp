vector<int> AnomalyDetector::identifyAnomalies(vector<double> data) {
    vector<int> anomalies;
    anomalies = zScoreMethod(data);
    if (anomalies.empty()) {
        anomalies = IQRMethod(data);
    }
    return anomalies;
}