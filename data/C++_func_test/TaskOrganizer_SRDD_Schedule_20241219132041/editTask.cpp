void TaskManager::editTask(int id) {
    if (id < 0 || tasks.size() <= id) {
        cout << "Invalid task ID!" << endl;
        return;
    }
    cout << "Editing Task: " << tasks[id].getName() << endl;
    string name, timeSlot;
    int priority;
    cout << "Enter new name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter new priority: ";
    cin >> priority;
    cout << "Enter new time slot: ";
    cin.ignore();
    getline(cin, timeSlot);
    tasks[id].setName(name);
    tasks[id].setPriority(priority);
    tasks[id].setTimeSlot(timeSlot);
}