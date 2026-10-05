void terminate(int sig) {
    log_event("Termination signal received. Cleaning up resources...");
    shutdown_network_monitor();
    shutdown_log_analysis();
    shutdown_behavior_monitor();
    running = 0;
}