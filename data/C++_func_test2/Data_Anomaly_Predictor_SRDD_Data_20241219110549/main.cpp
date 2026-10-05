int main() {
    DataLoader dataLoader;
    AnomalyDetector anomalyDetector;
    dataLoader.loadData("data.csv");
    dataLoader.normalizeData();
    anomalyDetector.trainModel(dataLoader.getData());
    anomalyDetector.predictAnomalies(dataLoader.getData());
    return 0;
}