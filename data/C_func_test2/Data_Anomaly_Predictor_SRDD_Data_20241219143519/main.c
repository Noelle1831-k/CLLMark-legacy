int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <datafile>\n", argv[0]);
        return 1;
    }
    char *datafile = argv[1];
    double *dataset = NULL;
    int data_size = 0;
    log_message("Loading data...");
    dataset = load_data(datafile, &data_size);
    if (dataset == NULL) {
        fprintf(stderr, "Failed to load data from %s\n", datafile);
        return 1;
    }
    log_message("Detecting anomalies...");
    double *anomalies = detect_anomalies(dataset, data_size);
    if (anomalies == NULL) {
        fprintf(stderr, "Anomaly detection failed.\n");
        free(dataset);
        return 1;
    }
    log_message("Displaying results...");
    display_dashboard(anomalies, data_size);
    free(dataset);
    free(anomalies);
    return 0;
}