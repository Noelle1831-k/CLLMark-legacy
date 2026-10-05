void TaskManager::removeTask() {
    string name;
    cout << "Enter the name of the task to remove: ";
    cin.ignore();
    getline(cin, name);
    for (std::vector<Task>::iterator it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getName() == name) {
            tasks.erase(it);
            cout << "Task removed successfully.\n";
            return;
        }
    }
    cout << "Task not found.\n";
}