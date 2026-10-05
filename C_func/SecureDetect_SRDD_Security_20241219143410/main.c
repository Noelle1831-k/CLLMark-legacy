int main() {
    signal(SIGINT, terminate);
    signal(SIGTERM, terminate);
    log_event("Starting SecureDetect application...");
    if (!initialize_network_monitor()) {
        log_event("Network monitoring initialization failed.");
        return 1;
    }
    if (!initialize_log_analysis()) {
        log_event("Log analysis initialization failed.");
        return 1;
    }
    if (!initialize_behavior_monitor()) {
        log_event("Behavior analysis initialization failed.");
        return 1;
    }
    log_event("SecureDetect is now monitoring for threats...");
    while (running) {
        analyze_network_traffic();
        analyze_system_logs();
        analyze_user_behavior();
        sleep(1); 
    }
    log_event("SecureDetect application has been terminated gracefully.");
    return 0;
}