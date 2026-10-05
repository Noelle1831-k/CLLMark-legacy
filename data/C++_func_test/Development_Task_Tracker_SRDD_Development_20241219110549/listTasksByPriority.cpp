vector<Task> TaskManager::listTasksByPriority() const {
    vector<Task> sortedTasks = tasks;
    sort(sortedTasks.begin(), sortedTasks.end(), [](const Task& a, const Task& b) {
        return a.getPriority() > b.getPriority();
    });
    return sortedTasks;
}