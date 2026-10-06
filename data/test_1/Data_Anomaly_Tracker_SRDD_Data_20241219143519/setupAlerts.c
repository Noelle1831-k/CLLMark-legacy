void setupAlerts(Anomalies *anomalies) {
    printf("Setting up alerts for anomalies...\n");
    for (int i = 0; i < anomalies->count; i++) {
        printf("Alert: Anomaly detected at row %d, column %d, value: %.2f\n",
               anomalies->entries[i].row,
               anomalies->entries[i].column,
               anomalies->entries[i].value);
    }
    printf("Alerts setup complete.\n");
}