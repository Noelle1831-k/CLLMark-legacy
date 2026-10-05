void startApplication() {
        cout << "Welcome to LanguageSense, your interactive language learning platform!" << endl;
        user.setUserPreferences();
        database.loadData();
        mainMenu();
    }