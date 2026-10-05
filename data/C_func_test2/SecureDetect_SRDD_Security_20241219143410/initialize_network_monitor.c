int initialize_network_monitor() {
    log_event("Initializing network monitoring...");
    memset(network_buffer, 0, MAX_BUFFER);
    return 1;
}