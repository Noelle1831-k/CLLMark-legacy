void handleUserInput(ExpenseManager &expenseManager, Budget &budget, ReceiptManager &receiptManager) {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: {
            double amount;
            string category, description, date, receiptPath;
            cout << "Enter amount: ";
            cin >> amount;
            cout << "Enter category: ";
            cin >> category;
            cout << "Enter description: ";
            cin.ignore();
            getline(cin, description);
            cout << "Enter date (YYYY-MM-DD): ";
            cin >> date;
            cout << "Enter receipt path: ";
            cin >> receiptPath;
            expenseManager.addExpense(amount, category, description, date, receiptPath);
            budget.checkBudget(amount);
            break;
        }
        case 2: {
            int id;
            cout << "Enter expense ID to remove: ";
            cin >> id;
            expenseManager.removeExpense(id);
            break;
        }
        case 3:
            expenseManager.listExpenses();
            break;
        case 4: {
            double limit;
            cout << "Enter budget limit: ";
            cin >> limit;
            budget.setBudgetLimit(limit);
            break;
        }
        case 5:
            expenseManager.generateReport();
            break;
        case 6:
            expenseManager.analyzeTrends();
            break;
        case 7: {
            int id;
            string path;
            cout << "Enter expense ID: ";
            cin >> id;
            cout << "Enter receipt path: ";
            cin >> path;
            receiptManager.uploadReceipt(id, path);
            break;
        }
        case 8: {
            int id;
            cout << "Enter expense ID to view receipt: ";
            cin >> id;
            cout << "Receipt Path: " << receiptManager.getReceiptPath(id) << endl;
            break;
        }
        case 9:
            cout << "Exiting application. Goodbye!\n";
            exit(0);
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}