int main() {
    int choice;
    Board *board;
    Objectives *objectives;
    VictoryCondition *victoryCondition;
    board = createBoard(10, 10);  
    objectives = createObjectives();
    victoryCondition = createVictoryCondition();
    while (1) {
        displayMainMenu();  
        choice = getUserInput();
        switch (choice) {
            case 1:  
                setupBoard(board);
                break;
            case 2:  
                defineObjectives(objectives);
                break;
            case 3:  
                setVictoryCondition(victoryCondition);
                break;
            case 4:  
                saveScenario(board, objectives, victoryCondition);
                break;
            case 5:  
                loadScenario(board, objectives, victoryCondition);
                break;
            case 6:  
                printf("Exiting the scenario creator...\n");
                freeBoard(board);
                freeObjectives(objectives);
                freeVictoryCondition(victoryCondition);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}