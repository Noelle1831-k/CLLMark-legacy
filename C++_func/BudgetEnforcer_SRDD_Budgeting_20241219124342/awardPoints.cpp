void GamificationManager::awardPoints(double amount) {
    points += static_cast<int>(amount / 10);
    if (points >= 100 && find(achievements.begin(), achievements.end(), "Budget Master") == achievements.end()) {
        achievements.push_back("Budget Master");
    }
}