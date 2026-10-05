void User::addGoal(string name, string category, double target) {
    goals.emplace_back(name, category, target);
}