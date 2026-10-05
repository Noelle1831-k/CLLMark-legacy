void GamificationManager::displayAchievements() {
    cout << "Achievements:\n";
    for (vector<string>::iterator it = achievements.begin(); it != achievements.end(); ++it) {
        cout << "- " << *it << endl;
    }
}