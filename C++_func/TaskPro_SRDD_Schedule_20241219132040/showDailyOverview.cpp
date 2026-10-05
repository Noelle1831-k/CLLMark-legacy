void TaskManager::showDailyOverview() {
    cout << "Daily Overview:" << endl;
    for (const auto& task : tasks) {
        cout << task.getTaskDetails() << endl;
    }
}