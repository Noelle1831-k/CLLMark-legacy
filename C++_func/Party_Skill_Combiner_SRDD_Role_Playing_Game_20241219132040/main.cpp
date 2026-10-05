int main() {
    srand(time(0)); 
    Party party;
    Optimizer optimizer;
    int choice;
    do {
        displayMenu();
        choice = getValidatedChoice();
        switch (choice) {
            case 1: {
                string name, role;
                cout << "Enter character name: ";
                cin >> name;
                cout << "Enter character role (e.g., Warrior, Mage, Archer): ";
                cin >> role;
                Character newChar(name, role);
                newChar.randomizeStats();
                party.addCharacter(newChar);
                cout << "Character added successfully!" << endl;
                break;
            }
            case 2: {
                string name;
                cout << "Enter the name of the character to remove: ";
                cin >> name;
                party.removeCharacter(name);
                break;
            }
            case 3: {
                party.displayParty();
                break;
            }
            case 4: {
                optimizer.optimizeParty(party);
                break;
            }
            case 5: {
                cout << "Exiting the application. Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (choice != 5);
    return 0;
}