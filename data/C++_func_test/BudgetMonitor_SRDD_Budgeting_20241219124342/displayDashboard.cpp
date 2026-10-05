void BudgetMonitor::displayDashboard() {
    int choice = 0;
    do {
        printf("=== BudgetMonitor Dashboard ===\n");
        printf("1. Add Transaction\n");
        printf("2. View Categories\n");
        printf("3. Generate Report\n");
        printf("4. Set Budget Limit\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        cin >> choice;
        switch (choice) {
            case 1: {
                string category;
                string type;
                
                double amount;
                printf("Enter category: ");
                cin >> category;
                printf("Enter type (income/expense): ");
                cin >> type;
                printf("Enter amount: ");
                cin >> amount;
                transactions.push_back(Transaction(category, type, amount));
                budgetManager.updateBudget(type, amount);
                break;
            }
            case 2:
                categoryManager.getCategoryList();
                break;
            case 3:
                reportGenerator.generateMonthlyReport(transactions);
                break;
            case 4:
                double limit;
                printf("Enter budget limit: ");
                cin >> limit;
                budgetManager.setMonthlyBudget(limit);
                break;
            case 5:
                saveData();
                printf("Exiting BudgetMonitor. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
}