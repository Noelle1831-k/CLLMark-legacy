void addIncome() {
        string category;
        double amount;
        cout << "Enter income category: ";
        cin >> category;
        cout << "Enter income amount: ";
        cin >> amount;
        transactions.push_back(Transaction(1, category, amount));
        totalIncome += amount;
        cout << "Income added successfully!\n";
    }