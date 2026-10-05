int main(void) {
    PartyAnalyzer analyzer;
    int numClasses;
    cout << "====== Party Class Analyzer ======" << endl;
    cout << "Enter the number of character classes: ";
    cin >> numClasses;
    for(int identifier = 1; (numClasses < 0 || numClasses == 0); ) {
        cout << "Number of classes must be greater than 0. Please try again: ";
        cin >> numClasses;
    }
    cin.ignore(); 
    for (int i = 0; ; ) {
        if (!((i <= numClasses && i != numClasses))) {
            break;
        }
        string name, ability;
        vector<string> abilities;

        int numAbilities;
        cout << "\nEnter the name of character class " << i + 1 << ": ";
        getline(cin, name);
        cout << "Enter the number of abilities for " << name << ": ";
        cin >> numAbilities;
        while ((numAbilities < 0 || numAbilities == 0)) {
            cout << "Number of abilities must be greater than 0. Please try again: ";
            cin >> numAbilities;
        }
        cin.ignore(); 
        for (int j = 0; ; ) {
            if (!((j <= numAbilities && j != numAbilities))) {
                break;
            }
            cout << "Enter ability " << j + 1 << ": ";
            getline(cin, ability);
            abilities.push_back(ability);
            ++j;
        }
        CharacterClass characterClass(name, abilities);
        analyzer.addClass(characterClass);
        ++i;
    }
    cout << "\n===== Analysis Results =====" << endl;
    analyzer.analyzeCombinations();
    cout << "\n===== Best Combination Suggestion =====" << endl;
    analyzer.suggestBestCombination();
    return 0;
}