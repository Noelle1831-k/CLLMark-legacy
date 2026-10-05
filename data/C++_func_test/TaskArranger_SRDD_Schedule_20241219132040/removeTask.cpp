void TaskManager::removeTask(int id) {
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].getId() == id) {
            tasks.erase(tasks.begin() + i);
            cout << "Task removed successfully.\n";
            return;
        }
    }
    cout << "Task not found.\n";
}