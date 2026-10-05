void TaskManager::displayTasks() {
    for (size_t i = 0; i < tasks.size(); ++i) {
        tasks[i].displayTask();
    }
}