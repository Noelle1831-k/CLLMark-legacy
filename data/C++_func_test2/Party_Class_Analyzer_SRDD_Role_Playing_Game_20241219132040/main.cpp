int main() {
    PartyAnalyzer analyzer;
    int numClasses;
    cout << "====== Party Class Analyzer ======" << endl;
    cout << "Enter the number of character classes: ";
    cin >> numClasses;
    while (numClasses <= 0) {
        cout << "Number of classes must be greater than 0. Please try again: ";
        cin >> numClasses;
    }
    cin.ignore(); 
    for (int i = 0; i < numClasses; i++) {
        string name;
        vector<string> abilities;
        string ability;
        int numAbilities;
        cout << "\nEnter the name of character class " << i + 1 << ": ";
        getline(cin, name);
        cout << "Enter the number of abilities for " << name << ": ";
        cin >> numAbilities;
        while (numAbilities <= 0) {
            cout << "Number of abilities must be greater than 0. Please try again: ";
            cin >> numAbilities;
        }
        cin.ignore(); 
        for (int j = 0; j < numAbilities; j++) {
            cout << "Enter ability " << j + 1 << ": ";
            getline(cin, ability);
            abilities.push_back(ability);
        }
        CharacterClass characterClass(name, abilities);
        analyzer.addClass(characterClass);
    }
    cout << "\n===== Analysis Results =====" << endl;
    analyzer.analyzeCombinations();
    cout << "\n===== Best Combination Suggestion =====" << endl;
    analyzer.suggestBestCombination();
    return 0;
}