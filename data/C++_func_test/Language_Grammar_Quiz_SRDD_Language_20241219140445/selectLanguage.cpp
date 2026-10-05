void User::selectLanguage() {
    cout << "Select Language (English/French/Spanish): ";
    cin >> language;
    for (int i = 0; i < language.size(); i++) {
        language[i] = tolower(language[i]);
    }
}