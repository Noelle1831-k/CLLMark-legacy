void generateVisualizations(Anomalies *anomalies) {
    printf("Generating visualizations...\n");
    for (int i = 0; i < anomalies->count; i++) {
        printf("Visualization: Anomaly at row %d, column %d with value %.2f\n",
               anomalies->entries[i].row,
               anomalies->entries[i].column,
               anomalies->entries[i].value);
    }
    printf("Visualizations complete.\n");
}