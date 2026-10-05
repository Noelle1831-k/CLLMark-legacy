int main() {
    int choice;
    while (1) {
        displayMenu();
        choice = getInput();
        if (!validateInput(choice, 1, 6)) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }
        switch (choice) {
            case 1:
                addIncome();
                break;
            case 2:
                addExpense();
                break;
            case 3:
                addCategory();
                break;
            case 4:
                listCategories();
                break;
            case 5:
                generateReport();
                break;
            case 6:
                printf("Exiting BudgetMonitor. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}