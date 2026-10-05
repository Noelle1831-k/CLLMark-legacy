int main() {
    UIHandler uiHandler;
    PartyOptimizer optimizer;
    Party party;
    cout << "Welcome to the RPG Party Formation Simulator!" << endl;
    while (true) {
        uiHandler.displayMenu();
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                party.addCharacter(uiHandler.inputCharacterDetails());
                break;
            case 2:
                optimizer.generateOptimalParty(party);
                break;
            case 3:
                uiHandler.displayParty(party);
                break;
            case 4:
                cout << "Exiting the application. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}