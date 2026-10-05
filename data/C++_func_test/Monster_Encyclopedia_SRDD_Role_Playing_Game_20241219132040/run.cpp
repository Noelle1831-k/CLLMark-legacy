void Application::run() {
    bool running = true;
    while (running) {
        showMenu();
        int choice;
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "Enter monster details:\n";
            string name, reward;
            int health, attack;
            vector<string> abilities, weaknesses;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Health: ";
            cin >> health;
            cout << "Attack: ";
            cin >> attack;
            cout << "Reward: ";
            cin.ignore();
            getline(cin, reward);
            cout << "Abilities (comma-separated): ";
            string abilityLine;
            getline(cin, abilityLine);
            abilities = {abilityLine};
            cout << "Weaknesses (comma-separated): ";
            string weaknessLine;
            getline(cin, weaknessLine);
            weaknesses = {weaknessLine};
            Monster newMonster(name, health, attack, abilities, weaknesses,
                               reward);
            database.addMonster(newMonster);
            break;
        }
        case 2: {
            cout << "Enter monster name to update: ";
            string name;
            cin.ignore();
            getline(cin, name);
            Monster *monster = database.searchMonster(name);
            if (monster) {
                cout << "Updating monster...\n";
                int health, attack;
                vector<string> abilities, weaknesses;
                string reward;
                cout << "Health: ";
                cin >> health;
                cout << "Attack: ";
                cin >> attack;
                cout << "Reward: ";
                cin.ignore();
                getline(cin, reward);
                cout << "Abilities (comma-separated): ";
                string abilityLine;
                getline(cin, abilityLine);
                abilities = {abilityLine};
                cout << "Weaknesses (comma-separated): ";
                string weaknessLine;
                getline(cin, weaknessLine);
                weaknesses = {weaknessLine};
                monster->updateStats(health, attack, abilities, weaknesses,
                                     reward);
            } else {
                cout << "Monster not found.\n";
            }
            break;
        }
        case 3:
            database.listMonsters();
            break;
        case 4:
            running = false;
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }
    }
}