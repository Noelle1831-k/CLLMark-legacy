int main() {
    cout << "Welcome to Finance Insights!" << endl;
    User user("John Doe", 5000.0);  
    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Transaction" << endl;
        cout << "2. View Financial Analysis" << endl;
        cout << "3. Generate Reports" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        choice = Utility::ValidateInput();
        switch (choice) {
        case 1: {
            double amount;
            string category, date;
            cout << "Enter amount: ";
            cin >> amount;
            cout << "Enter category: ";
            cin >> category;
            cout << "Enter date (YYYY-MM-DD): ";
            cin >> date;
            user.AddTransaction(Transaction(amount, category, date));
            cout << "Transaction added successfully!" << endl;
            break;
        }
        case 2: {
            FinanceAnalyzer analyzer;
            double totalExpenses = analyzer.GetTotalExpenses(user);
            double totalSavings = analyzer.CalculateSavings(user);
            cout << "\nFinancial Analysis:" << endl;
            cout << "Total Expenses: " << Utility::FormatCurrency(totalExpenses) << endl;
            cout << "Total Savings: " << Utility::FormatCurrency(totalSavings) << endl;
            analyzer.GenerateSuggestions(user);
            break;
        }
        case 3: {
            ReportGenerator generator;
            generator.GenerateSummaryReport(user);
            generator.GenerateGraphicalReport(user);
            break;
        }
        case 4:
            cout << "Exiting the application. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    return 0;
}