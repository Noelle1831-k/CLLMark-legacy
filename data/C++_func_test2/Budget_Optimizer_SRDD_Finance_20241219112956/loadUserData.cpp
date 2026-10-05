void loadUserData() {
        cout << "Loading user data..." << endl;
        user = User(5000); 
        user.addExpense("Rent", 1500);
        user.addExpense("Groceries", 500);
        user.addExpense("Utilities", 300);
    }