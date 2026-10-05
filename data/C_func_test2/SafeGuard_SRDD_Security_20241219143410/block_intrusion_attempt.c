void block_intrusion_attempt() {
    printf("Intrusion detected! Blocking malicious IP: 203.0.113.45\n");
    log_event("Intrusion attempt blocked.");
}