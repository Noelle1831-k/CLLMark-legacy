void displayBudgetBreakdown() {
        map<string, double> incomeCategories, expenseCategories;
        for (size_t i = 0; i < transactions.size(); i++) {
            if (transactions[i].getType() == 1) {
                incomeCategories[transactions[i].getCategory()] += transactions[i].getAmount();
            } else {
                expenseCategories[transactions[i].getCategory()] += transactions[i].getAmount();
            }
        }
        cout << "\n--- Budget Breakdown ---\n";
        cout << "Income:\n";
        for (map<string, double>::iterator it = incomeCategories.begin(); it != incomeCategories.end(); ++it) {
            cout << "  " << it->first << ": " << it->second << "\n";
        }
        cout << "Expenses:\n";
        for (map<string, double>::iterator it = expenseCategories.begin(); it != expenseCategories.end(); ++it) {
            cout << "  " << it->first << ": " << it->second << "\n";
        }
    }