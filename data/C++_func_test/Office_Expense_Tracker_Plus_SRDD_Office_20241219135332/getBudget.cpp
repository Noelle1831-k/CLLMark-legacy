double Budget::getBudget(const string& category) const {
    auto it = categoryBudgets.find(category);
    if (it != categoryBudgets.end()) {
        return it->second;
    }
    return 0.0;
}