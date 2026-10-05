int main() {
    string fileName;
    cout << "Enter the dataset file name (CSV format): ";
    cin >> fileName;
    DataImporter dataImporter;
    vector<double> data = dataImporter.importData(fileName);
    AnomalyDetector anomalyDetector;
    vector<int> anomalies = anomalyDetector.identifyAnomalies(data);
    VisualizationManager visualizationManager;
    visualizationManager.visualizeData(data, anomalies);
    visualizationManager.generateReport(anomalies);
    return 0;
}