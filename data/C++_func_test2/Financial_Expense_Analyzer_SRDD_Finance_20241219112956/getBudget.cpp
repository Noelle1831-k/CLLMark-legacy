double UserBudget::getBudget(string category) const {
    if (categoryBudgets.find(category) != categoryBudgets.end()) {
        return categoryBudgets.at(category);
    }
    return 0.0;
}