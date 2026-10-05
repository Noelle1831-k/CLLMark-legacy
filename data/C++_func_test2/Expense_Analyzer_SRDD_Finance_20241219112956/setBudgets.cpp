void ExpenseAnalyzerApp::setBudgets() {
    char choice;
    do {
        double amount;
        string category;
        cout << "Enter budget category: ";
        cin >> category;
        cout << "Enter budget amount: ";
        cin >> amount;
        userBudget.setBudget(category, amount);
        cout << "Set another budget? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}