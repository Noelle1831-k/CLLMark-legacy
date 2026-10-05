void endSession(LanguageSenseApp *app) {
    printf("Ending session for user: %s\n", app->userProfile.username);
    saveProfile(&app->userProfile);
    printf("Session ended.\n");
}