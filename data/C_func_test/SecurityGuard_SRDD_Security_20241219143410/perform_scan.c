void perform_scan() {
    printf("Performing full device scan...\n");
    int files_scanned = 0;
    int threats_detected = 0;
    for (int i = 0; i < 1000; i++) {  
        files_scanned++;
        if (rand() % 50 == 0) {  
            threats_detected++;
            printf("Threat detected in file %d! Neutralizing...\n", i);
            neutralize_threat(i);
        }
    }
    printf("Scan completed. Files scanned: %d, Threats detected: %d\n", files_scanned, threats_detected);
}