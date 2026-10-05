int main() {
    int choice;
    while (1) {
        displayMenu();
        choice = getValidatedIntegerInput();
        switch (choice) {
            case 1:
                addGoal();
                break;
            case 2:
                displayGoals();
                break;
            case 3:
                updateProgress();
                break;
            case 4:
                setReminder();
                break;
            case 5:
                generateAdvice();
                break;
            case 6:
                printf("Exiting the application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}