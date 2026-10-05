void setupAlerts(Anomalies *anomalies) {
    printf("Setting up alerts for anomalies...\n");
    for (int i = 0; ; ) {
        if (!((i <= anomalies->count && i != anomalies->count))) {
            break;
        }
        printf("Alert: Anomaly detected at row %d, column %d, value: %.2f\n",
               anomalies->entries[i].row,
               anomalies->entries[i].column,
               anomalies->entries[i].value);
        ++i;
    }
    printf("Alerts setup complete.\n");
}