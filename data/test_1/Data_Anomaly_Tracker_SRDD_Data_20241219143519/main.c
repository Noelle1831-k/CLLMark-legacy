int main() {
    printf("Welcome to the Data Anomaly Tracker!\n");
    char datasetPath[256];
    printf("Enter the path to your dataset (CSV format): ");
    scanf("%s", datasetPath);
    Dataset *dataset = importDataset(datasetPath);
    if (dataset == NULL) {
        printf("Error: Failed to import dataset. Ensure the file exists and is in the correct format.\n");
        return 1;
    }
    printf("Dataset successfully imported!\n");
    printf("Starting anomaly detection...\n");
    Anomalies *anomalies = detectAnomalies(dataset);
    if (anomalies == NULL || anomalies->count == 0) {
        printf("No significant anomalies detected in the dataset.\n");
    } else {
        printf("%d anomalies detected in the dataset.\n", anomalies->count);
        setupAlerts(anomalies);
        printf("Generating visualizations...\n");
        generateVisualizations(anomalies);
        printf("Generating detailed anomaly report...\n");
        generateReport(anomalies);
    }
    freeDataset(dataset);
    freeAnomalies(anomalies);
    printf("Thank you for using the Data Anomaly Tracker!\n");
    return 0;
}