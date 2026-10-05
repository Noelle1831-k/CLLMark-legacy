void AchievementManager::viewAllAchievements() const {
    if (achievements.empty()) {
        cout << "No achievements to display!" << endl;
        return;
    }
    cout << "Listing all achievements:" << endl;
    for (size_t i = 0; i < achievements.size(); i++) {
        achievements[i].displayAchievement();
    }
}