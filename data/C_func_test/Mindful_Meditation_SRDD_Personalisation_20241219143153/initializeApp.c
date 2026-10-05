void initializeApp() {
    printf("Initializing MindfulMeditation...\n");
    srand(time(NULL)); 
    loadPreferences();
    loadLibrary();
    initializeProgressTracker();
    initializeReminders();
}