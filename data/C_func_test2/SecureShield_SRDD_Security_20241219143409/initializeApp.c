void initializeApp() {
    printf("Initializing SecureShield...\n");
    loadThreatDatabase();
    initializeBrowserExtension();
    printf("SecureShield is now running.\n");
}