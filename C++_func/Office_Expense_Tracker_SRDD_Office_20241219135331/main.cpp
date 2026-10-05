int main() {
    BudgetManager budgetManager;
    ExpenseManager expenseManager(budgetManager);
    ReportGenerator reportGenerator;
    int choice = 0;
    while (choice != 7) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                string category, description;
                float amount;
                cout << "Enter category: ";
                cin >> category;
                cout << "Enter amount: ";
                cin >> amount;
                cout << "Enter description: ";
                cin.ignore();
                getline(cin, description);
                expenseManager.addExpense(category, amount, description);
                break;
            }
            case 2:
                expenseManager.viewExpenses();
                break;
            case 3: {
                float budget;
                cout << "Enter budget amount: ";
                cin >> budget;
                budgetManager.setBudget(budget);
                break;
            }
            case 4:
                cout << "Remaining Budget: " << budgetManager.getRemainingBudget() << endl;
                break;
            case 5:
                reportGenerator.generateMonthlyReport(expenseManager);
                break;
            case 6:
                expenseManager.analyzeExpenses();
                break;
            case 7:
                cout << "Exiting application. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}