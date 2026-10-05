void raise_alert(const char *message) {
    printf("ALERT: %s\n", message);
    log_alert(message);
    provide_mitigation_recommendations();
}