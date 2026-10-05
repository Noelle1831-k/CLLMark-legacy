void checkForRealTimeUpdates() {
    while (realTimeUpdatesRunning) {
        printf("Checking for real-time news updates...\n");
        fetchLatestNews();
        sleep(10);  
    }
}