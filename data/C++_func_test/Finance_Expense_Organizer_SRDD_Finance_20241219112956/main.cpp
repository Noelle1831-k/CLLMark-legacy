int main(int argc, char *argv[]) {
    ExpenseManager manager;
    int choice = 0;
    while (true) {
        cout << "\n-----------------------------------\n";
        cout << "Finance Expense Organizer\n";
        cout << "1. Add Expense\n";
        cout << "2. Display All Expenses\n";
        cout << "3. Display Expenses by Category\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                double amount;
                string description;
                string category;
                
                cout << "Enter the amount: $";
                cin >> amount;
                if (!isValidAmount(amount)) {
                    cout << "Invalid amount. Please enter a positive value.\n";
                    break;
                }
                cout << "Enter the category (e.g., Groceries, Transportation, Entertainment): ";
                cin.ignore();
                getline(cin, category);
                printFormattedCategory(category);
                cout << "Enter a brief description: ";
                getline(cin, description);
                Expense newExpense(amount, category, description);
                manager.addExpense(newExpense);
                break;
            }
            case 2:
                manager.displayAllExpenses();
                break;
            case 3: {
                string category;
                cout << "Enter category to display (e.g., Groceries, Transportation, Entertainment): ";
                cin.ignore();
                getline(cin, category);
                manager.displayExpensesByCategory(category);
                break;
            }
            case 4:
                cout << "Exiting the program...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}