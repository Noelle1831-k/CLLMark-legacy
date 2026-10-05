int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        choice = getValidatedInteger();
        switch (choice) {
            case 1:
                allocateExpenses();
                break;
            case 2:
                viewExpenseForecast();
                break;
            case 3:
                manageBills();
                break;
            case 4:
                trackGoals();
                break;
            case 5:
                printf("Exiting the application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}