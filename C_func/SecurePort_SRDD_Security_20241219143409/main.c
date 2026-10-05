int main() {
    printf("Initializing SecurePort...\n");
    if (!initialize_firewall()) {
        fprintf(stderr, "Failed to initialize firewall. Exiting...\n");
        exit(EXIT_FAILURE);
    }
    pthread_t monitor_thread, firewall_thread;
    if (pthread_create(&monitor_thread, NULL, traffic_monitor_thread, NULL) != 0) {
        perror("Error creating traffic monitor thread");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&firewall_thread, NULL, firewall_maintenance_thread, NULL) != 0) {
        perror("Error creating firewall maintenance thread");
        exit(EXIT_FAILURE);
    }
    printf("SecurePort is running. Monitoring network ports and managing the firewall...\n");
    pthread_join(monitor_thread, NULL);
    pthread_join(firewall_thread, NULL);
    return 0;
}