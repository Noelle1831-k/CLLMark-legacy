int main() {
    printf("Initializing SecureTrack System...\n");
    loadData();
    initializeUsers();
    if (startTracking()) {
        printf("Tracking started successfully.\n");
    } else {
        handleError("Failed to start tracking.");
    }
    monitorActivity();
    saveData();
    printf("SecureTrack System shutting down.\n");
    return 0;
}