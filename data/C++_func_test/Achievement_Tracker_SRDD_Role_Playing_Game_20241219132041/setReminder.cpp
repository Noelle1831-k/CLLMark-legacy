void AchievementManager::setReminder(const string& name) {
    Achievement* achievement = findAchievement(name);
    if (achievement) {
        int days;
        cout << "Enter the number of days until the deadline: ";
        scanf("%d", &days);
        time_t now = time(0), deadline = now + (days * 24 * 60 * 60);

        achievement->setDeadline(deadline);
        cout << "Reminder set for \"" << name << "\"!" << endl;
        displayReminder(*achievement);
    } else {
        cout << "Achievement \"" << name << "\" not found!" << endl;
    }
}