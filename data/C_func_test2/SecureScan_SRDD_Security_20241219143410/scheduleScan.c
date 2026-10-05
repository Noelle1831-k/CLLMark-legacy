void scheduleScan() {
    printf("Scheduling scan...\n");
    int delay = 5 + (rand() % 15); 
    printf("Scan scheduled in %d seconds.\n", delay);
    sleep(delay);
    printf("\nScheduled scan starting now.\n");
    performScan();
}