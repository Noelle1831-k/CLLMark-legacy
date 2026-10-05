int main() {
    int choice;
    char sportName[50], team1[50], team2[50];
    int gameId, score1, score2;
    initializeSports();
    initializeGames();
    initializeScores();
    while (1) {
        displayMenu();
        choice = getIntInput();
        switch (choice) {
            case 1:
                printf("Enter sport name: ");
                getStringInput(sportName, 50);
                addSport(sportName);
                break;
            case 2:
                listSports();
                break;
            case 3:
                printf("Enter sport name: ");
                getStringInput(sportName, 50);
                printf("Enter team 1 name: ");
                getStringInput(team1, 50);
                printf("Enter team 2 name: ");
                getStringInput(team2, 50);
                addGame(sportName, team1, team2);
                break;
            case 4:
                printf("Enter sport name: ");
                getStringInput(sportName, 50);
                listGames(sportName);
                break;
            case 5:
                printf("Enter game ID: ");
                gameId = getIntInput();
                printf("Enter score for team 1: ");
                score1 = getIntInput();
                printf("Enter score for team 2: ");
                score2 = getIntInput();
                updateScore(gameId, score1, score2);
                break;
            case 6:
                printf("Enter game ID: ");
                gameId = getIntInput();
                viewScore(gameId);
                break;
            case 7:
                printf("Exiting application...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}