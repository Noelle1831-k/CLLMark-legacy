void handle_exit_signal(int signum) {
    keep_running = 0;
    printf("\nShutting down SecurityMonitor...\n");
}