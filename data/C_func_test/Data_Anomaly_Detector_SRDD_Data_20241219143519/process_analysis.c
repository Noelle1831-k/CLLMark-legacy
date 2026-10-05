void process_analysis(char *filename, char *fields) {
    printf("Analyzing data...\n");
    detect_statistical_anomalies(filename, fields);
    detect_ml_anomalies(filename, fields);
    generate_report(filename, fields);
    generate_chart(filename, fields);
    printf("Analysis complete. Reports and visualizations generated.\n");
}