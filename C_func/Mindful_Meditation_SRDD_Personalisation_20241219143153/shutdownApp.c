void shutdownApp() {
    printf("Shutting down MindfulMeditation...\n");
    savePreferences();
    saveProgress();
    clearReminders();
}