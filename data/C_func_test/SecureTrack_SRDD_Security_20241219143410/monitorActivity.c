void monitorActivity() {
    printf("Monitoring user activities...\n");
    for (int i = 0; i < 10; i++) {
        printf("Activity %d monitored.\n", i + 1);
        logActivity("Sample activity");
        if (i % 3 == 0) {
            generateAlert("Suspicious activity detected!");
        }
    }
}