Achievement* AchievementManager::findAchievement(const string& name) {
    for (size_t i = 0; i < achievements.size(); i++) {
        if (achievements[i].getName() == name) {
            return &achievements[i];
        }
    }
    return nullptr;
}