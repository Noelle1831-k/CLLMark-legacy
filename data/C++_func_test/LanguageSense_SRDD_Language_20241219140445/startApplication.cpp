void startApplication() {
        printf("Welcome to LanguageSense, your interactive language learning platform!\n");
        user.setUserPreferences();
        database.loadData();
        mainMenu();
    }