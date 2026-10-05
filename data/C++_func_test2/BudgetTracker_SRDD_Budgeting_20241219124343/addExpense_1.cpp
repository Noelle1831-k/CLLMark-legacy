void addExpense() {
        string category, description;
        double amount;
        cout << "Enter expense category: ";
        cin.ignore();
        getline(cin, category);
        cout << "Enter expense description: ";
        getline(cin, description);
        cout << "Enter expense amount: ";
        cin >> amount;
        if (cin.fail()) {
            cerr << "Error: Invalid amount entered. Please try again." << endl;
            clearInputBuffer();
            return;
        }
        Category* cat = findCategory(category);
        if (cat == nullptr) {
            categories.emplace_back(category);
            cat = &categories.back();
        }
        cat->addExpense(description, amount);
    }