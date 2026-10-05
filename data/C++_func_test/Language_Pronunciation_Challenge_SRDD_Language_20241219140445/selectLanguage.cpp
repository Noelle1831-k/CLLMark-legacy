string LanguageManager::selectLanguage() {
    cout << "Select your target language:" << endl;
    cout << "1. English" << endl;
    cout << "2. Spanish" << endl;
    cout << "3. French" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: return "English";
        case 2: return "Spanish";
        case 3: return "French";
        default: return "English";
    }
}