int main() {
    ExpenseList expenseList;
    initializeExpenseList(&expenseList);
    User user;
    strcpy(user.name, "Default User");
    user.income = 5000.0;
    user.savingsGoal = 1000.0;
    int choice;
    char filename[50];
    do {
        clearScreen();
        displayMenu();
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1: {
                char category[50], date[20];
                double amount;
                printf("Enter expense category: ");
                fgets(category, sizeof(category), stdin);
                category[strcspn(category, "\n")] = '\0'; 
                printf("Enter expense amount: ");
                scanf("%lf", &amount);
                getchar(); 
                strcpy(date, getCurrentDate());
                addExpense(&expenseList, category, amount, date);
                printf("Expense added successfully!\n");
                pauseExecution();
                break;
            }
            case 2:
                displayExpenses(&expenseList);
                pauseExecution();
                break;
            case 3: {
                double total = calculateTotalExpenses(&expenseList);
                printf("Total Expenses: $%.2f\n", total);
                pauseExecution();
                break;
            }
            case 4: {
                double total = calculateTotalExpenses(&expenseList);
                generateSavingsRecommendation(&user, total);
                pauseExecution();
                break;
            }
            case 5:
                printf("Enter filename to save data: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0'; 
                saveDataToFile(&expenseList, filename);
                printf("Data saved successfully!\n");
                pauseExecution();
                break;
            case 6:
                printf("Enter filename to load data: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0'; 
                loadDataFromFile(&expenseList, filename);
                printf("Data loaded successfully!\n");
                pauseExecution();
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                pauseExecution();
        }
    } while (choice != 7);
    freeExpenseList(&expenseList);
    return 0;
}