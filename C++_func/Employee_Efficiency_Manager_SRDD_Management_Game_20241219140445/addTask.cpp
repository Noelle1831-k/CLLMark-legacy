void TeamManager::addTask(Task task) {
    tasks.push_back(task);
    cout << "Task added: " << task.getDescription() << endl;
}