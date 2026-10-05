void TaskManager::addTask() {
    int id, priority;
    string title, description, deadline, category;
    cout << "Enter Task ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Description: ";
    getline(cin, description);
    cout << "Enter Deadline: ";
    getline(cin, deadline);
    cout << "Enter Priority (1-5): ";
    cin >> priority;
    cin.ignore();
    cout << "Enter Category: ";
    getline(cin, category);
    Task newTask(id, title, description, deadline, priority, category);
    tasks.push_back(newTask);
    cout << "Task added successfully.\n";
}