void TaskManager::deleteTask(int taskID) {
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].getTaskID() == taskID) {
            tasks.erase(tasks.begin() + i);
            cout << "Task deleted successfully!" << endl;
            return;
        }
    }
    cout << "Task not found!" << endl;
}