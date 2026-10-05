void Schedule::deleteTask(int id) {
    auto it = remove_if(tasks.begin(), tasks.end(), [id](Task &t) { return t.getId() == id; });
    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        cout << "Task deleted successfully.\n";
    } else {
        cout << "Task not found.\n";
    }
}