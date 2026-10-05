void viewTransactions() const {
        cout << "Transactions for category: " << name << endl;
        for (size_t i = 0; i < transactions.size(); i++) {
            cout << i + 1 << ". " << transactions[i].first << ": $" << fixed << setprecision(2) << transactions[i].second << endl;
        }
    }