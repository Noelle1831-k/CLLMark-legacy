void TimeManager::displaySchedule() {
    cout << "Task Schedule:\n";
    for (int i = 0; i < schedule.size(); i++) {
        cout << " - " << schedule[i].first << ": " << schedule[i].second << " minutes\n";
    }
}