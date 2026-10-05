int main(int argc, char *argv[]) {
    initializeUser();
    while (1) {
        int choice = displayMainMenu();
        switch (choice) {
            case 1:
                startGame();
                break;
            case 2:
                showProgressDashboard();
                break;
            case 3:
                printf("Exiting the game. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}