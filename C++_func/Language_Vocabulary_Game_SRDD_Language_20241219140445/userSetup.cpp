void userSetup(UserProfile &user) {
    string language;
    int difficulty;
    cout << "Enter your language choice (e.g., English, Spanish, French): ";
    cin >> language;
    user.setLanguage(language);
    cout << "Select difficulty level (1 - Easy, 2 - Medium, 3 - Hard): ";
    cin >> difficulty;
    user.setDifficulty(difficulty);
}