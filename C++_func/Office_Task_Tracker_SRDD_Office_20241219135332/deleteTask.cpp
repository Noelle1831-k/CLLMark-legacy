void TaskManager::deleteTask(int id) {
    tasks.erase(remove_if(tasks.begin(), tasks.end(), [id](Task &task) { return task.getId() == id; }), tasks.end());
    cout << "Task deleted successfully.\n";
}