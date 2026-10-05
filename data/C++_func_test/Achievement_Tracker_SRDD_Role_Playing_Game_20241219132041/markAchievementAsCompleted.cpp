void AchievementManager::markAchievementAsCompleted(const string& name) {
    Achievement* achievement = findAchievement(name);
    if (achievement) {
        achievement->markAsCompleted();
        cout << "Achievement \"" << name << "\" marked as completed!" << endl;
    } else {
        cout << "Achievement \"" << name << "\" not found!" << endl;
    }
}