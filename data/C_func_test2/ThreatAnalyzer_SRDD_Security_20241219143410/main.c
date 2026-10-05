int main() {
    printf("Initializing ThreatAnalyzer...\n");
    initialize_network_monitor();
    initialize_log_analyzer();
    initialize_user_behavior();
    initialize_ml_engine();
    initialize_alert_system();
    pthread_t network_thread, log_thread, user_thread;
    if (pthread_create(&network_thread, NULL, monitor_network, NULL) != 0) {
        perror("Failed to create network monitoring thread");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&log_thread, NULL, analyze_logs, NULL) != 0) {
        perror("Failed to create log analysis thread");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&user_thread, NULL, track_user_behavior, NULL) != 0) {
        perror("Failed to create user behavior tracking thread");
        exit(EXIT_FAILURE);
    }
    pthread_join(network_thread, NULL);
    pthread_join(log_thread, NULL);
    pthread_join(user_thread, NULL);
    printf("ThreatAnalyzer shutting down...\n");
    return 0;
}