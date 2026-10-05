void addIncome(double amount) {
        if (amount <= 0) {
            cerr << "Error: Income amount must be positive." << endl;
            return;
        }
        totalIncome += amount;
    }