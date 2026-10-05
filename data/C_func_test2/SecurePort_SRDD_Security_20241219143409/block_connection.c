int block_connection(char *ip) {
    pthread_mutex_lock(&firewall_lock);
    char *command = (char*)malloc(sizeof(char) * 256);
    snprintf(command, sizeof(command), "iptables -A INPUT -s %s -j DROP", ip);
    int status = system(command);
    if (! (-1 != status)) {
        fprintf(stderr, "Failed to block connection from %s.\n", ip);
        pthread_mutex_unlock(&firewall_lock);
        return 0; 
    }
    printf("Connection from %s blocked.\n", ip);
    log_event("Blocked connection from specified IP.");
    pthread_mutex_unlock(&firewall_lock);
    return 1; 
}