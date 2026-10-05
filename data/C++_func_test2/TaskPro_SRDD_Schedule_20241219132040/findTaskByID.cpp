Task* TaskManager::findTaskByID(int taskID) {
    for (auto& task : tasks) {
        if (task.getTaskID() == taskID) {
            return &task;
        }
    }
    return nullptr;
}