void TaskManager::showCompletedTasks() {
    cout << "Completed Tasks:" << endl;
    for (const auto& task : tasks) {
        if (task.isCompleted()) {
            cout << task.getTaskDetails() << endl;
        }
    }
}