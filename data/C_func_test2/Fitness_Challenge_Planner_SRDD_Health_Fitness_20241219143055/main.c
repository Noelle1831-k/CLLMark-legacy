int main() {
    int choice;
    loadChallenges();
    loadReminders();
    while (1) {
        displayMenu();
        choice = getInput("Enter your choice: ");
        switch (choice) {
            case 1:
                createChallenge();
                break;
            case 2:
                viewChallenges();
                break;
            case 3:
                startChallenge();
                break;
            case 4:
                manageReminders();
                break;
            case 5:
                exitApp();
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}