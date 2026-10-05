int main() {
    ExpensePlanner planner;
    double income, targetSavings;
    cout << "Welcome to the Expense Planner!" << endl;
    cout << "Please follow the instructions to manage your finances effectively." << endl;
    while (true) {
        cout << "Enter your monthly income: ";
        cin >> income;
        if (cin.fail() || income <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number for income." << endl;
        } else {
            break;
        }
    }
    planner.setIncome(income);
    while (true) {
        cout << "Enter your target savings: ";
        cin >> targetSavings;
        if (cin.fail() || targetSavings < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a non-negative number for savings." << endl;
        } else {
            break;
        }
    }
    planner.setTargetSavings(targetSavings);
    int numCategories;
    while (true) {
        cout << "Enter number of expense categories: ";
        cin >> numCategories;
        if (cin.fail() || numCategories <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive integer for categories." << endl;
        } else {
            break;
        }
    }
    for (int i = 0; i < numCategories; i++) {
        string category;
        double amount;
        cout << "Enter expense category name: ";
        cin >> category;
        while (true) {
            cout << "Enter allocated amount for " << category << ": ";
            cin >> amount;
            if (cin.fail() || amount < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a non-negative number for amount." << endl;
            } else {
                break;
            }
        }
        planner.addExpenseCategory(category, amount);
    }
    planner.displayExpenseSummary();
    planner.suggestSavings();
    cout << "Thank you for using the Expense Planner. Have a great day!" << endl;
    return 0;
}