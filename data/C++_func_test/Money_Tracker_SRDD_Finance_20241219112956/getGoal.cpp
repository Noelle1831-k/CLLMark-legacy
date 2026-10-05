double Budget::getGoal(const std::string& category) const {
    auto it = goals.find(category);
    if (it != goals.end()) {
        return it->second;
    }
    return 0.0;
}