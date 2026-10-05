void EventManager::manageTasks() {
    int choice;
    cout << "1. Add Task\n2. View Tasks\n3. Mark Task Complete\nEnter choice: ";
    cin >> choice;
    if (choice == 1) {
        string taskDescription;
        cout << "Enter Task Description: ";
        cin.ignore();
        getline(cin, taskDescription);
        Task task;
        task.setTaskDetails(taskDescription);
        tasks.push_back(task);
        cout << "Task added successfully!" << endl;
    } else if (choice == 2) {
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << "Task " << i + 1 << ": ";
            tasks[i].getTaskDetails();
        }
    } else if (choice == 3) {
        int taskIndex;
        cout << "Enter Task Number to Mark Complete: ";
        cin >> taskIndex;
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].markComplete();
        } else {
            cout << "Invalid Task Number!" << endl;
        }
    } else {
        cout << "Invalid Choice!" << endl;
    }
}