void *firewall_maintenance_thread(void *args) {
    monitor_firewall();
    return NULL;
}