int main() {
    cout << "Welcome to BudgetPro - Your Financial Companion!" << endl;
    User user("John Doe");
    BudgetManager budgetManager;
    Visualizer visualizer;
    RecommendationEngine recommender;
    int choice = 0;
    while (choice != 5) {
        cout << "\nMenu:\n";
        cout << "1. Add Income\n2. Add Expense\n3. View Budget Report\n4. Get Recommendations\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            double income;
            cout << "Enter income amount: ";
            cin >> income;
            user.addIncome(income);
            budgetManager.addIncome(income);
            break;
        }
        case 2: {
            double expense;
            string category;
            cout << "Enter expense amount: ";
            cin >> expense;
            cout << "Enter expense category: ";
            cin >> category;
            Transaction transaction(budgetManager.generateTransactionID(), expense, "2024-12-19", category);
            user.addExpense(expense);
            budgetManager.addTransaction(transaction);
            break;
        }
        case 3:
            budgetManager.generateReport();
            visualizer.generatePieChart(budgetManager.getExpenseData());
            break;
        case 4:
            recommender.provideRecommendations(user, budgetManager);
            break;
        case 5:
            cout << "Thank you for using BudgetPro!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}