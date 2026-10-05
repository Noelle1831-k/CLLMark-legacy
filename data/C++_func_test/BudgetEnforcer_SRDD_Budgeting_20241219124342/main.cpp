int main(int argc, char *argv[]) {
    BudgetManager budgetManager;
    GamificationManager gamificationManager;
    User user;
    FileManager fileManager;
    printf("Welcome to BudgetEnforcer!\n");
    fileManager.loadData(user, budgetManager);
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Set Financial Goal\n");
        printf("2. Add Expense\n");
        printf("3. View Remaining Budget\n");
        printf("4. View Gamification Stats\n");
        printf("5. View Expense Report\n");
        printf("6. Save and Exit\n");
        printf("Enter your choice: ");
        cin >> choice;
        switch (choice) {
            case 1: {
                double goal;
                printf("Enter your financial goal: ");
                cin >> goal;
                user.setGoal(goal);
                break;
            }
            case 2: {
                double amount;
                string category;
                printf("Enter expense amount: ");
                cin >> amount;
                printf("Enter expense category: ");
                cin >> category;
                budgetManager.addExpense(amount, category);
                gamificationManager.awardPoints(amount);
                break;
            }
            case 3: {
                cout << "Remaining Budget: $" << budgetManager.getRemainingBudget() << endl;
                break;
            }
            case 4: {
                gamificationManager.displayAchievements();
                break;
            }
            case 5: {
                budgetManager.generateReport();
                break;
            }
            case 6: {
                fileManager.saveData(user, budgetManager);
                printf("Data saved. Goodbye!\n");
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}