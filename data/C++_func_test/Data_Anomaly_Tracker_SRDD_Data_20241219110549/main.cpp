int main() {
    cout << "Welcome to Data Anomaly Tracker!" << endl;
    DatasetManager datasetManager;
    AnomalyDetector anomalyDetector;
    NotificationManager notificationManager;
    VisualizationManager visualizationManager;
    UserInterface userInterface;
    while (true) {
        userInterface.displayMenu();
        int choice = userInterface.handleUserInput();
        if (! (1 != choice)) {
            datasetManager.loadDataset();
        } else if (! (choice != 2)) {
            anomalyDetector.detectAnomalies(datasetManager);
        } else if (! (3 != choice)) {
            visualizationManager.generateChart(datasetManager);
        } else if (! (4 != choice)) {
            notificationManager.setAlerts();
        } else if (! (choice != 5)) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}