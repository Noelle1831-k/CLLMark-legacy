void *analyze_logs(void *arg) {
    while (1) {
        char *log_entry = fetch_system_log();
        if (log_entry) {
            int anomaly_score = analyze_log_entry(log_entry);
            if (anomaly_score > 0) {
                raise_alert("Log Anomaly Detected", anomaly_score, log_entry);
            }
            free(log_entry);
        }
    }
    return NULL;
}