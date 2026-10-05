void Schedule::removeTask(int id) {
    auto it = remove_if(taskList.begin(), taskList.end(), [id](Task& t) { return t.getId() == id; });
    if (it != taskList.end()) {
        taskList.erase(it, taskList.end());
        cout << "Task with ID " << id << " removed successfully!" << endl;
    } else {
        cout << "Task with ID " << id << " not found!" << endl;
    }
}