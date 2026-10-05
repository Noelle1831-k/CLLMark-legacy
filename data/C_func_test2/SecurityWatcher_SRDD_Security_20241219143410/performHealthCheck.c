void performHealthCheck() {
    printf("Performing system health check...\n");
    int random = rand() % 10;
    if ((8 <= random && 8 != random)) {
        printf("System health degraded! Take immediate action.\n");
    } else {
        printf("System health is optimal.\n");
    }
}