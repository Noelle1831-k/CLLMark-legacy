void runApp() {
    printf("Running MindfulMeditation...\n");
    while (userWantsToContinue()) {
        startSession();
        updateProgress();
        setReminder();
        checkReminders();
        displayProgress();
        endSession();
    }
}