void stop_monitoring() {
    keep_monitoring = false;
    pthread_join(monitor_thread, NULL);
    printf("Network monitoring stopped.\n");
}