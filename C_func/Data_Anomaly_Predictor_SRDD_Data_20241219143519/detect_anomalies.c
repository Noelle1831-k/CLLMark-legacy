double* detect_anomalies(double *data, int size) {
    double *anomalies = (double *)calloc(size, sizeof(double)); 
    if (!anomalies) {
        log_message("Memory allocation for anomalies failed.");
        return NULL;
    }
    double mean = calculate_mean(data, size);
    double stddev = calculate_stddev(data, size, mean);
    log_message("Calculating anomalies...");
    for (int i = 0; i < size; i++) {
        if (fabs(data[i] - mean) > 2 * stddev) {  
            anomalies[i] = data[i];  
        }
    }
    log_message("Anomaly detection completed.");
    return anomalies;
}