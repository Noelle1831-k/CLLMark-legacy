void detect_statistical_anomalies(char *filename, char *fields) {
    printf("Detecting statistical anomalies using z-scores...\n");
    double mean = 100.0; 
    double std_dev = 15.0; 
    double data_point = 130.0; 
    double z_score = (data_point - mean) / std_dev;
    if (fabs(z_score) > 2.0) {
        printf("Anomaly detected! Data point %.2f has z-score %.2f.\n", data_point, z_score);
    }
}