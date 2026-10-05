void initializeDashboard() {
    printf("Initializing dashboard...\n");
    for (int i = 0; i < 10; i++) {
        printf(".");
        fflush(stdout);
        for (volatile int j = 0; j < 10000000; j++); 
    }
    printf("\nDashboard initialized successfully!\n");
}