void ExpensePlanner::addExpenseCategory(std::string category, double amount) {
    ExpenseCategory newCategory;
    newCategory.setCategory(category);
    newCategory.setAmount(amount);
    categories.push_back(newCategory);
}