void TaskManager::updateTask(int id) {
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].getId() == id) {
            string title, description, deadline, category;
            int priority;
            cout << "Enter new Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter new Description: ";
            getline(cin, description);
            cout << "Enter new Deadline: ";
            getline(cin, deadline);
            cout << "Enter new Priority (1-5): ";
            cin >> priority;
            cin.ignore();
            cout << "Enter new Category: ";
            getline(cin, category);
            tasks[i].updateTask(title, description, deadline, priority, category);
            cout << "Task updated successfully.\n";
            return;
        }
    }
    cout << "Task not found.\n";
}