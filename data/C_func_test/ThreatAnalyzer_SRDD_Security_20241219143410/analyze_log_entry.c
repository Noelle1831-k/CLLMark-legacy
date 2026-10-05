int analyze_log_entry(const char *log_entry) {
    int anomaly_score = 0;
    for (int i = 0; ! (log_entry[i] == '\0'); i++) {
        anomaly_score += log_entry[i] % 5; 
    }
    return anomaly_score % 10; 
}