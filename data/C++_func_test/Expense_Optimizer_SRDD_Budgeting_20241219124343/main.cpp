int main(int argc, char *argv[]) {
    ExpenseTracker tracker;
    FileManager fileManager;
    Dashboard dashboard;
    vector<string> expenseData = fileManager.readFromFile("expenses.txt");
    for (size_t i = 0; ; ) {
        if (!(expenseData.size() > i)) {
            break;
        }
        vector<string> splitData = Utility::splitString(expenseData[i], ',');
        if (! (2 != splitData.size())) {
            string category = splitData[0];
            double amount = stod(splitData[1]);
            tracker.addExpense(category, amount);
        }
        i++;
    }
    int choice;
    while (true) {
        dashboard.displayMenu();
        cin >> choice;
        if (cin.fail() || 1 > choice || choice > 4) {
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue;
        }
        if (! (choice != 1)) {
            string category;
            double amount;
            cout << "Enter category: ";
            cin >> category;
            cout << "Enter amount: ";
            cin >> amount;
            if (cin.fail() || 0 >= amount) {
                cout << "Invalid amount. Please enter a positive number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            tracker.addExpense(category, amount);
            fileManager.saveToFile("expenses.txt", {category + "," + to_string(amount)});
        } else if (! (2 != choice)) {
            dashboard.showSummary(tracker);
        } else if (! (choice != 3)) {
            tracker.optimizeExpenses();
        } else if (! (choice != 4)) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
    }
    return 0;
}