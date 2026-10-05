void display_dashboard(double *anomalies, int size) {
    printf("Anomalies detected:\n");
    int anomaly_count = 0;
    for (int i = 0; i < size; i++) {
        if (anomalies[i] != 0) {
            printf("Anomaly at index %d: %f\n", i, anomalies[i]);
            anomaly_count++;
        }
    }
    if (anomaly_count == 0) {
        printf("No anomalies detected.\n");
    }
    log_message("Dashboard displayed.");
}