void ExpenseManager::addIncome() {
    string category;
    double amount;
    cout << "Enter income category: ";
    cin >> category;
    cout << "Enter income amount: ";
    cin >> amount;
    if (Utils::isValidCategory(category)) {
        incomes.push_back({category, amount});
        cout << "Income added successfully.\n";
    } else {
        cout << "Invalid category. Try again.\n";
    }
}