bool Budget::isGoalMet(const std::string& category, double currentAmount) const {
    auto it = goals.find(category);
    if (it != goals.end()) {
        return currentAmount <= it->second;
    }
    return false;
}