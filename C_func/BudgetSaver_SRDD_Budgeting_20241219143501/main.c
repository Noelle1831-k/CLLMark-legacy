int main() {
    int choice;
    double amount;
    char category[50];
    double goal;
    char buffer[1024];
    initializeExpenseTracker();
    initializeSavingsGoal();
    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter expense amount: ");
                if (scanf("%lf", &amount) != 1) {
                    printf("Invalid amount. Please enter a valid number.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Enter expense category: ");
                scanf("%s", category);
                addExpense(amount, category);
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                printf("Enter your savings goal: ");
                if (scanf("%lf", &goal) != 1) {
                    printf("Invalid goal. Please enter a valid number.\n");
                    while (getchar() != '\n');
                    break;
                }
                setSavingsGoal(goal);
                break;
            case 4:
                viewSavingsProgress();
                break;
            case 5:
                generateRecommendations();
                break;
            case 6:
                saveDataToFile("expenses.txt", serializeExpenses());
                saveDataToFile("savings.txt", serializeSavings());
                break;
            case 7:
                loadDataFromFile("expenses.txt", buffer, sizeof(buffer));
                deserializeExpenses(buffer);
                loadDataFromFile("savings.txt", buffer, sizeof(buffer));
                deserializeSavings(buffer);
                break;
            case 8:
                printf("Exiting BudgetSaver. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}