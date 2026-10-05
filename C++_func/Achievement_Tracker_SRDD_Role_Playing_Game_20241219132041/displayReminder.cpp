void AchievementManager::displayReminder(const Achievement& achievement) {
    cout << "Reminder: Achievement \"" << achievement.getName() << "\" is due on " << ctime(&achievement.getDeadline()) << endl;
}