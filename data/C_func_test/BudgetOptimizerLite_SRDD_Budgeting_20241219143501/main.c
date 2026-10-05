int main() {
    Budget budget = createBudget(); 
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        choice = getIntInput();
        switch (choice) {
            case 1: {
                double income;
                printf("Enter income amount: ");
                income = getDoubleInput();
                addIncome(&budget, income);
                printf("Income added successfully!\n");
                break;
            }
            case 2: {
                char category[50];
                double expense;
                printf("Enter expense category: ");
                getStringInput(category, sizeof(category));
                printf("Enter expense amount: ");
                expense = getDoubleInput();
                addExpense(&budget, category, expense);
                printf("Expense added successfully!\n");
                break;
            }
            case 3: {
                double goal;
                printf("Enter your budget goal: ");
                goal = getDoubleInput();
                setBudgetGoal(&budget, goal);
                printf("Budget goal set successfully!\n");
                break;
            }
            case 4: {
                visualizeBudget(budget);
                break;
            }
            case 5: {
                saveBudgetToFile(budget, "budget_data.txt");
                printf("Budget saved successfully!\n");
                break;
            }
            case 6: {
                budget = loadBudgetFromFile("budget_data.txt");
                printf("Budget loaded successfully!\n");
                break;
            }
            case 7: {
                printf("Thank you for using BudgetOptimizerLite! Goodbye!\n");
                exit(0);
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}