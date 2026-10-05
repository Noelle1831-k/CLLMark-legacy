int main(int argc, char *argv[]) {
    printf("Initializing SecurityMonitor...\n");
    signal(SIGINT, handle_exit_signal);
    initialize_network_monitor();
    initialize_alert_system();
    initialize_log_manager();
    printf("Starting network monitoring...\n");
    start_monitoring();
    printf("SecurityMonitor is running. Press Ctrl+C to exit.\n");
    while (keep_running) {
        display_dashboard();
        sleep(1);
    }
    printf("SecurityMonitor has stopped.\n");
    return 0;
}