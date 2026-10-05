void Task::inputDetails() {
    cout << "Enter task name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter task description: ";
    getline(cin, description);
    cout << "Enter task deadline: ";
    getline(cin, deadline);
    cout << "Enter task category: ";
    getline(cin, category);
}