int main(void) {
    UserInterface ui;
    DataImporter importer;
    AnomalyDetector detector;
    Visualizer visualizer;
    ui.displayMenu();
    string filePath = ui.getUserInput("Enter the path of the dataset file: ");
    vector<vector<double>> data = importer.importData(filePath);
    detector.detectAnomalies(data);
    visualizer.plotScatter(data);
    visualizer.plotLineGraph(data);
    visualizer.plotHistogram(data);
    return 0;
}