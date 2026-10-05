void startMonitoring() {
    printf("Starting Real-Time Monitoring...\n");
    for (int i = 0; i < 5; i++) { 
        scanForThreats();
    }
    printf("Monitoring Completed.\n");
}