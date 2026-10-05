void Expense::displayExpenseDetails() const {
    cout << "Amount: $" << fixed << setprecision(2) << amount << endl;
    cout << "Category: " << category << endl;
    cout << "Description: " << description << endl;
}