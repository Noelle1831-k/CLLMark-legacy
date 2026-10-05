void DayOverview::generateOverview(const TaskManager& taskManager) const {
    cout << "\n--- Day Overview ---\n";
    taskManager.listTasks();
    cout << "--------------------\n";
}