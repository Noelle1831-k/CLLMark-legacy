Task* TaskManager::getTaskById(int taskId) {
    for (auto& task : tasks) {
        if (task.getId() == taskId) {
            return &task;
        }
    }
    return nullptr;
}