void AnomalyDetector::detectAnomalies(DatasetManager &datasetManager) {
    vector<vector<double>> data = datasetManager.getDataset();
    cout << "Detecting anomalies..." << endl;
    calculateStatistics(data);
    applyMLModel(data);
    cout << "Anomaly detection complete!" << endl;
}