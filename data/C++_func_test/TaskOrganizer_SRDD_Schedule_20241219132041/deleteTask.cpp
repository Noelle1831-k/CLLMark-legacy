void TaskManager::deleteTask(int id) {
    if (id < 0 || id >= tasks.size()) {
        cout << "Invalid task ID!" << endl;
        return;
    }
    tasks.erase(tasks.begin() + id);
}