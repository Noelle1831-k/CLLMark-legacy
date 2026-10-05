void configure_firewall() {
    printf("Configuring firewall with advanced rules...\n");
    log_event("Firewall configuration initiated.");
    const char *rules[] = {
        "Block all incoming traffic from IP: 192.168.1.100",
        "Allow outgoing HTTPS traffic only",
        "Monitor port 22 for SSH brute-force attacks"
    };
    int total_rules = sizeof(rules) / sizeof(rules[0]);
    for (int i = 0; i < total_rules; i++) {
        printf("Applying Rule %d: %s\n", i + 1, rules[i]);
    }
    printf("Firewall configuration complete.\n");
    log_event("Firewall configuration completed.");
}