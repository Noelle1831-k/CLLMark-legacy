bool UserBudget::categoryExists(string category) const {
    return categoryBudgets.find(category) != categoryBudgets.end();
}