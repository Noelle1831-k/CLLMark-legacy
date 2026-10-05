void blockMaliciousWebsite() {
    printf("Scanning for malicious websites...\n");
    int maliciousDetected = rand() % 2; 
    if (maliciousDetected) {
        printf("Malicious website detected and blocked.\n");
        logEvent("Malicious website blocked.");
    } else {
        printf("No malicious websites found.\n");
    }
}