int main() {
    initializeSystem();
    int choice;
    do {
        printf("\nOffice Expense Management System\n");
        printf("--------------------------------\n");
        printf("1. Input Expense\n");
        printf("2. Categorize Expense\n");
        printf("3. Set Budget\n");
        printf("4. Generate Report\n");
        printf("5. Analyze Expenditure\n");
        printf("6. Save Data\n");
        printf("7. Load Data\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        switch (choice) {
            case 1:
                inputExpense();
                break;
            case 2:
                categorizeExpense();
                break;
            case 3:
                setBudget();
                break;
            case 4:
                generateReport();
                break;
            case 5:
                analyzeExpenditure();
                break;
            case 6:
                saveData();
                break;
            case 7:
                loadData();
                break;
            case 8:
                printf("Exiting...\n");
                cleanupSystem();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);
    return 0;
}