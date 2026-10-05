void monitor_network() {
    printf("Monitoring network traffic...\n");
    int suspicious_packet = rand() % 100;
    if (suspicious_packet < 5) {
        raise_alert("Suspicious network activity detected.");
        log_message("Network monitor: Suspicious packet detected.");
    }
}