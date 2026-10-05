void initialize(LanguageSenseApp *app) {
    printf("Initializing LanguageSense Application...\n");
    loadProfile(&app->userProfile);
    printf("Initialization complete.\n");
}