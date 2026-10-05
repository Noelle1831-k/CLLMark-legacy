void AchievementManager::addAchievement(const string& name, const string& description, const string& category) {
    achievements.push_back(Achievement(name, description, category));
    cout << "Achievement \"" << name << "\" added successfully!" << endl;
}