void TaskManager::addTask(const string& name, int priority, const string& dueDate) {
    Task newTask(name, priority, dueDate);
    tasks.push_back(newTask);
}