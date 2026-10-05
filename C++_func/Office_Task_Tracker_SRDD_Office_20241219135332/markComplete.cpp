void TaskManager::markComplete(int id) {
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].getId() == id) {
            tasks[i].markComplete();
            cout << "Task marked as complete.\n";
            return;
        }
    }
    cout << "Task not found.\n";
}