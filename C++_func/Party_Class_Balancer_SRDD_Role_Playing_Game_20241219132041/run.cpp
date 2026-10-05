void run() {
        PartyAnalyzer analyzer;
        int numClasses;
        cout << "Enter the number of character classes (minimum 3): ";
        while (!(cin >> numClasses) || numClasses < 3) {
            cout << "Invalid input. Enter an integer greater than or equal to 3: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cin.ignore(); 
        for (int i = 0; i < numClasses; i++) {
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
        }
        analyzer.analyze();
        analyzer.recommendParty();
    }