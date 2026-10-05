void TaskManager::addTask(const string& name, const string& category, const string& deadline) {
    Task newTask(nextId++, name, category, deadline);
    taskList.push_back(newTask);
}