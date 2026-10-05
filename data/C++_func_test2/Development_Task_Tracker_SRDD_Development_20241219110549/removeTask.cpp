void TaskManager::removeTask(int taskId) {
    tasks.erase(remove_if(tasks.begin(), tasks.end(), [taskId](const Task& task) {
        return task.getId() == taskId;
    }), tasks.end());
}