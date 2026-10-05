void start_monitoring() {
    keep_monitoring = true;
    if (pthread_create(&monitor_thread, NULL, monitor_traffic, NULL) != 0) {
        fprintf(stderr, "Error: Failed to create monitoring thread.\n");
        exit(EXIT_FAILURE);
    }
}