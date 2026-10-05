void AchievementManager::updateAchievement(const string& name) {
    Achievement* achievement = findAchievement(name);
    if (achievement) {
        string newDescription, newCategory;
        cout << "Enter new description: ";
        cin.ignore();
        getline(cin, newDescription);
        cout << "Enter new category: ";
        getline(cin, newCategory);
        achievement->updateDetails(newDescription, newCategory);
        cout << "Achievement \"" << name << "\" updated successfully!" << endl;
    } else {
        cout << "Achievement \"" << name << "\" not found!" << endl;
    }
}