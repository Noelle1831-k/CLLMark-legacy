void TaskManager::removeTask() {
    int id;
    cout << "Enter Task ID to remove: ";
    cin >> id;
    for (vector<Task>::iterator it = taskList.begin(); it != taskList.end(); ++it) {
        if (it->getTaskID() == id) {
            taskList.erase(it);
            cout << "Task removed successfully." << endl;
            return;
        }
    }
    cout << "Task not found." << endl;
}