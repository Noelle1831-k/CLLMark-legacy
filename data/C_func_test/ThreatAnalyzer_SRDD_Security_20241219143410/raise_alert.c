void raise_alert(const char *message, int severity, const char *details) {
    printf("[ALERT] %s (Severity: %d)\nDetails: %s\n", message, severity, details);
}