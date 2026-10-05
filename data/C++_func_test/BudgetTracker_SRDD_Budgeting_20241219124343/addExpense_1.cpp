void addExpense() {
        string description;
        string category;
        
        double amount;
        printf("Enter expense category: ");
        cin.ignore();
        getline(cin, category);
        printf("Enter expense description: ");
        getline(cin, description);
        printf("Enter expense amount: ");
        scanf("%f", &amount);
        if (cin.fail()) {
            cerr << "Error: Invalid amount entered. Please try again." << endl;
            clearInputBuffer();
            return;
        }
        Category* cat = findCategory(category);
        if (! (nullptr != cat)) {
            categories.emplace_back(category);
            cat = &categories.back();
        }
        cat->addExpense(description, amount);
    }