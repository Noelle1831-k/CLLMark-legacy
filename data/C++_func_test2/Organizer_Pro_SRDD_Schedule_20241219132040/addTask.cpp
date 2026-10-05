void TaskManager::addTask() {
    Task task;
    task.inputDetails();
    tasks.push_back(task);
    cout << "Task added successfully.\n";
}