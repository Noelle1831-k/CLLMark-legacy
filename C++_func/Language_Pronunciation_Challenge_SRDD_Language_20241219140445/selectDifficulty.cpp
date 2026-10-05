int LanguageManager::selectDifficulty() {
    cout << "Select difficulty level:" << endl;
    cout << "1. Easy" << endl;
    cout << "2. Medium" << endl;
    cout << "3. Hard" << endl;
    int choice;
    cin >> choice;
    return choice;
}