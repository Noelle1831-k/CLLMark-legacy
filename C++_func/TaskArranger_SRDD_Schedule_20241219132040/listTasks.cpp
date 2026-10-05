void TaskManager::listTasks() const {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        tasks[i].displayTask();
    }
}