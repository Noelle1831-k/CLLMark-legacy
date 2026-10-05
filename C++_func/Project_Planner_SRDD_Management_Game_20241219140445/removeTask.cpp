void Project::removeTask() {
    int taskIndex;
    cout << "Enter task index to remove (0-based): ";
    cin >> taskIndex;
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex);
        cout << "Task removed successfully." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}