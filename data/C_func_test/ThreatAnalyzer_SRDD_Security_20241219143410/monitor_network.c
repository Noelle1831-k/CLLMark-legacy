void *monitor_network(void *arg) {
    while (1) {
        char *data = capture_network_traffic();
        if (data) {
            int threat_level = analyze_network_data(data);
            if (threat_level > 0) {
                raise_alert("Network Threat Detected", threat_level, data);
            }
            free(data);
        }
    }
    return NULL;
}