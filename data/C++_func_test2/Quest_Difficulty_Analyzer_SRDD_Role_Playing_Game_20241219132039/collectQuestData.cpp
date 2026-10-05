Quest QuestAnalyzer::collectQuestData() {
    int enemyStrength, requiredSkills;
    double timeConstraints;
    string questName;
    cout << "Enter quest name: ";
    cin.ignore();
    getline(cin, questName);
    do {
        cout << "Enter enemy strength (1-100): ";
        cin >> enemyStrength;
        if (!validateInput(enemyStrength, 1, 100)) {
            cout << "Invalid input. Please enter a value between 1 and 100." << endl;
        }
    } while (!validateInput(enemyStrength, 1, 100));
    do {
        cout << "Enter required skills (1-100): ";
        cin >> requiredSkills;
        if (!validateInput(requiredSkills, 1, 100)) {
            cout << "Invalid input. Please enter a value between 1 and 100." << endl;
        }
    } while (!validateInput(requiredSkills, 1, 100));
    do {
        cout << "Enter time constraints (hours, positive value): ";
        cin >> timeConstraints;
        if (timeConstraints <= 0) {
            cout << "Invalid input. Please enter a positive value." << endl;
        }
    } while (timeConstraints <= 0);
    return Quest(enemyStrength, requiredSkills, timeConstraints, questName);
}