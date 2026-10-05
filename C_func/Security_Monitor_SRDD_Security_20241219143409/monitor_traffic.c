void *monitor_traffic(void *arg) {
    while (keep_monitoring) {
        char packet[256];
        snprintf(packet, sizeof(packet), "Packet data: %d", rand());
        if (analyze_packet(packet)) {
            raise_alert("Suspicious activity detected!");
        }
        log_network_activity(packet);
        sleep(1); 
    }
    return NULL;
}