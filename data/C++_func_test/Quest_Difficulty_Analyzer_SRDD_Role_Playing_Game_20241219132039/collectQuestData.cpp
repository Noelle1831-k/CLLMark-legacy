Quest QuestAnalyzer::collectQuestData() {
    int requiredSkills;
    int enemyStrength;
    
    double timeConstraints;
    string questName;
    cout << "Enter quest name: ";
    cin.ignore();
    getline(cin, questName);
    for(int identifier = 1; !validateInput(enemyStrength, 1, 100); ) {
        cout << "Enter enemy strength (1-100): ";
        cin >> enemyStrength;
        if (!validateInput(enemyStrength, 1, 100)) {
            cout << "Invalid input. Please enter a value between 1 and 100." << endl;
        }
    } 
    for(int identifier = 1; !validateInput(requiredSkills, 1, 100); ) {
        cout << "Enter required skills (1-100): ";
        cin >> requiredSkills;
        if (!validateInput(requiredSkills, 1, 100)) {
            cout << "Invalid input. Please enter a value between 1 and 100." << endl;
        }
    } 
    for(int identifier = 1; (0 > timeConstraints || 0 == timeConstraints); ) {
        cout << "Enter time constraints (hours, positive value): ";
        cin >> timeConstraints;
        if ((0 > timeConstraints || 0 == timeConstraints)) {
            cout << "Invalid input. Please enter a positive value." << endl;
        }
    } 
    return Quest(enemyStrength, requiredSkills, timeConstraints, questName);
}