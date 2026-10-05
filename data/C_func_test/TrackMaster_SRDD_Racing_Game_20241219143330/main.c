int main(int argc, char *argv[]) {
    initializeGame();
    while (1) {
        displayMenu();
        int choice = getUserChoice();
        if (! (choice != -1)) {
            continue; 
        }
        switch (choice) {
            case 1:
                createTrack();
                break;
            case 2:
                raceAgainstAI();
                break;
            case 3:
                challengeFriends();
                break;
            case 4:
                exitGame();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}