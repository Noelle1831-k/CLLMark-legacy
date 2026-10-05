void Dashboard::addTaskToProject() {
    int projectId, taskId, priority;
    string name, description;
    cout << "Enter Project ID: ";
    cin >> projectId;
    for (auto& project : projects) {
        if (projectId == project.project_id) {
            cout << "Enter Task ID: ";
            cin >> taskId;
            cin.ignore();
            cout << "Enter Task Name: ";
            getline(cin, name);
            cout << "Enter Task Description: ";
            getline(cin, description);
            cout << "Enter Task Priority (1-5): ";
            cin >> priority;
            project.addTask(Task(taskId, name, description, priority));
            cout << "Task added successfully!" << endl;
            return;
        }
    }
    cout << "Project not found!" << endl;
}