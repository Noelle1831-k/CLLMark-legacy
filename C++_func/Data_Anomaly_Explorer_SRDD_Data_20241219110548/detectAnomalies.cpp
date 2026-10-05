void AnomalyDetector::detectAnomalies(const vector<vector<double>>& data) {
    applyStatisticalMethods(data);
    applyMachineLearningMethods(data);
}