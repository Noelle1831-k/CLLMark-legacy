void handleIncome() {
        double amount;
        string source;
        cout << "Enter income amount: ";
        cin >> amount;
        cout << "Enter income source: ";
        cin.ignore();
        getline(cin, source);
        incomeTracker.addIncome(amount, source);
        cout << "Income added successfully.\n";
    }