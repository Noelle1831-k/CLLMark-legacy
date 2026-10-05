int main() {
    int choice;
    while (1) {
        clearScreen();
        displayMenu();
        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input! Please enter a number.\n");
            continue;
        }
        switch (choice) {
            case 1:
                handleEmployeeInput();
                break;
            case 2:
                handleManagerInput();
                break;
            case 3:
                exitApplication();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        pauseExecution();
    }
    return 0;
}