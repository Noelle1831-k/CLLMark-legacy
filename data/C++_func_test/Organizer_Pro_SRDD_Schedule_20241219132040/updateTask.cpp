void TaskManager::updateTask() {
    string name;
    cout << "Enter the name of the task to update: ";
    cin.ignore();
    getline(cin, name);
    for (std::vector<Task>::iterator it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getName() == name) {
            it->inputDetails();
            cout << "Task updated successfully.\n";
            return;
        }
    }
    cout << "Task not found.\n";
}