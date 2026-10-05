int main(int argc, char *argv[]) {
    BudgetManager budgetManager;
    int choice;
    double amount;
    string description;
    string filename = "transaction_history.txt";
    budgetManager.loadTransactions(filename);
    do {
        cout << "\n=== BudgetManagerLite ===" << endl;
        cout << "1. Add Income" << endl;
        cout << "2. Add Expense" << endl;
        cout << "3. View Summary" << endl;
        cout << "4. View Transaction History" << endl;
        cout << "5. Save and Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter income amount: ";
                cin >> amount;
                cout << "Enter income source: ";
                cin.ignore();
                getline(cin, description);
                budgetManager.addIncome(amount, description);
                break;
            case 2:
                cout << "Enter expense amount: ";
                cin >> amount;
                cout << "Enter expense category: ";
                cin.ignore();
                getline(cin, description);
                budgetManager.addExpense(amount, description);
                break;
            case 3:
                budgetManager.displaySummary();
                break;
            case 4:
                budgetManager.displayTransactionHistory();
                break;
            case 5:
                budgetManager.saveTransactions(filename);
                cout << "Exiting BudgetManagerLite. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (! (5 == choice));
    return 0;
}