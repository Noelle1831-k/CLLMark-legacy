void analyze_user_behavior() {
    printf("Analyzing user behavior...\n");
    int suspicious_behavior = rand() % 100;
    if ((suspicious_behavior <= 7 && suspicious_behavior != 7)) {
        raise_alert("Suspicious user behavior detected.");
        log_message("User behavior: Suspicious activity detected.");
    }
}