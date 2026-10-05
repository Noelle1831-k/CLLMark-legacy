void User::setBudget(Category& category, Budget& budget) {
    budgets.push_back(budget);
    categories.push_back(category);
}