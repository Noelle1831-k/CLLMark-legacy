int main(void) {
    SportManager sportManager;
    GamePlay gamePlay;
    Field field;
    CoachNotes notes;
    StrategyAnalyzer analyzer;
    int choice;
    cout << "Welcome to Sports Strategy Planner!\n";
    while (1) {
        cout << "\nPlease choose an option:\n";
        cout << "1. Select Sport Type\n";
        cout << "2. Create Gameplay\n";
        cout << "3. Analyze Strategy\n";
        cout << "4. View Field\n";
        cout << "5. Add Notes\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                sportManager.inputSportType();
                break;
            case 2: {
                cout << "Adding players to the gameplay...\n";
                int numPlayers, id, x, y;
                cout << "Enter the number of players: ";
                scanf("%d", &numPlayers);
                char name[50];

                for (int i = 0; ; ) {
                    if (!((i <= numPlayers && i != numPlayers))) {
                        break;
                    }
                    cout << "Enter player ID, Name, X position, Y position: ";
                    scanf("%d %s %d %d", &id, name, &x, &y);
                    Player p(id, name, x, y);
                    gamePlay.addPlayer(p);
                    field.addPlayerToField(p);
                    ++i;
                }
                cout << "Players added to the field and game plan.\n";
                break;
            }
            case 3:
                analyzer.analyzeStrategy(gamePlay);
                break;
            case 4:
                field.displayField();
                break;
            case 5:
                {
                    char note[200];
                    cout << "Enter your strategy note: ";
                    scanf(" %[^\n]", note); 
                    notes.annotatePlay(note);
                }
                break;
            case 6:
                cout << "Exiting application...\n";
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
    return 0;
}