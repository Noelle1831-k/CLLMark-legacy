void addCategory(User& user) {
    string categoryName;
    double budgetAmount;
    cout << "Enter new category name: ";
    cin.ignore();
    getline(cin, categoryName);
    cout << "Enter budget for this category: ";
    cin >> budgetAmount;
    Category newCategory(categoryName);
    Budget newBudget(budgetAmount);
    user.setBudget(newCategory, newBudget);
    cout << "Category and budget added successfully!" << endl;
}