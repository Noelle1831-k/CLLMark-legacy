void manageAccount(User &user) {
        Account account;
        Report report;
        int option;
        do {
            cout << "\n--- Budget Buddy Menu ---\n";
            cout << "1. Add Transaction\n";
            cout << "2. View Transactions\n";
            cout << "3. Generate Monthly Report\n";
            cout << "4. Generate Annual Report\n";
            cout << "5. Logout\n";
            cout << "Enter your choice: ";
            cin >> option;
            switch (option) {
                case 1:
                    account.addTransaction();
                    break;
                case 2:
                    account.viewTransactions();
                    break;
                case 3:
                    report.generateMonthlyReport();
                    break;
                case 4:
                    report.generateAnnualReport();
                    break;
                case 5:
                    cout << "Logging out..." << endl;
                    break;
                default:
                    cout << "Invalid option. Try again." << endl;
            }
        } while (option != 5);
    }