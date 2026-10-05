void Project::addTask() {
    string taskName, taskDescription;
    int priority;
    cout << "Enter task name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
    getline(cin, taskName);
    cout << "Enter task description: ";
    getline(cin, taskDescription);
    cout << "Enter task priority (1-5): ";
    cin >> priority;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
    Task newTask(taskName, taskDescription, "Not Started", priority);
    tasks.push_back(newTask);
    cout << "Task added successfully." << endl;
}