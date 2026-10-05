int main() {
    SportManager sportManager;
    GamePlay gamePlay;
    Field field;
    CoachNotes notes;
    StrategyAnalyzer analyzer;
    int choice;
    printf("Welcome to Sports Strategy Planner!\n");
    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Select Sport Type\n");
        printf("2. Create Gameplay\n");
        printf("3. Analyze Strategy\n");
        printf("4. View Field\n");
        printf("5. Add Notes\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                sportManager.inputSportType();
                break;
            case 2: {
                printf("Adding players to the gameplay...\n");
                int numPlayers;
                printf("Enter the number of players: ");
                scanf("%d", &numPlayers);
                char name[50];
                int id, x, y;
                for (int i = 0; i < numPlayers; i++) {
                    printf("Enter player ID, Name, X position, Y position: ");
                    scanf("%d %s %d %d", &id, name, &x, &y);
                    Player p(id, name, x, y);
                    gamePlay.addPlayer(p);
                    field.addPlayerToField(p);
                }
                printf("Players added to the field and game plan.\n");
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
                    printf("Enter your strategy note: ");
                    scanf(" %[^\n]", note); 
                    notes.annotatePlay(note);
                }
                break;
            case 6:
                printf("Exiting application...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}