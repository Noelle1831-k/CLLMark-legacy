void TaskManager::updateTask() {
    int id;
    cout << "Enter Task ID to update: ";
    cin >> id;
    for (vector<Task>::iterator it = taskList.begin(); it != taskList.end(); ++it) {
        if (it->getTaskID() == id) {
            string name, desc;
            time_t dl;
            cout << "Enter new Task Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new Description: ";
            getline(cin, desc);
            cout << "Enter new Deadline (epoch time): ";
            cin >> dl;
            it->setTaskDetails(id, name, desc, dl);
            cout << "Task updated successfully." << endl;
            return;
        }
    }
    cout << "Task not found." << endl;
}