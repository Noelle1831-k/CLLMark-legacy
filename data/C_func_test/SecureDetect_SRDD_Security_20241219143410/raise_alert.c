void raise_alert(const char *message) {
    printf("[ALERT]: %s\n", message);
    log_event(message);
}