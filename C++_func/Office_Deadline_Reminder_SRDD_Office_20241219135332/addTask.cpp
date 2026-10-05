void TaskManager::addTask() {
    int id;
    string name, desc;
    time_t dl;
    cout << "Enter Task ID: ";
    cin >> id;
    cout << "Enter Task Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Description: ";
    getline(cin, desc);
    cout << "Enter Deadline (epoch time): ";
    cin >> dl;
    Task newTask(id, name, desc, dl);
    taskList.push_back(newTask);
    cout << "Task added successfully." << endl;
}