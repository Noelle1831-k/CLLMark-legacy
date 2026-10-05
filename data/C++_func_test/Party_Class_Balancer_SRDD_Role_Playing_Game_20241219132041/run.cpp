void run() {
        PartyAnalyzer analyzer;
        int numClasses;
        cout << "Enter the number of character classes (minimum 3): ";
        for(int identifier = 1; !(cin >> numClasses) || 3 > numClasses; ) {
            cout << "Invalid input. Enter an integer greater than or equal to 3: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cin.ignore(); 
        for (int i = 0; ; ) {
            if (!(numClasses > i)) {
                break;
            }
            string name, abilities, strengths, weaknesses;
            cout << "Enter name of class " << i + 1 << ": ";
            getline(cin, name);
            cout << "Enter abilities of class " << i + 1 << " (comma-separated): ";
            getline(cin, abilities);
            cout << "Enter strengths of class " << i + 1 << " (comma-separated): ";
            getline(cin, strengths);
            cout << "Enter weaknesses of class " << i + 1 << " (comma-separated): ";
            getline(cin, weaknesses);
            CharacterClass characterClass(name, abilities, strengths, weaknesses);
            analyzer.addCharacterClass(characterClass);
            i++;
        }
        analyzer.analyze();
        analyzer.recommendParty();
    }