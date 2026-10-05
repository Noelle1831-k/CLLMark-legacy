void UserInterface::handleUserInput() {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: {
            int id;
            string name;
            cout << "Enter Task ID: ";
            cin >> id;
            cout << "Enter Task Name: ";
            cin >> name;
            Task task(id, name);
            taskManager.addTask(task);
            break;
        }
        case 2: {
            int id;
            cout << "Enter Task ID to remove: ";
            cin >> id;
            taskManager.removeTask(id);
            break;
        }
        case 3: {
            vector<Task> tasks = taskManager.listAllTasks();
            for (const auto& task : tasks) {
                showTaskDetails(task);
            }
            break;
        }
        case 4: {
            vector<Task> tasks = taskManager.listTasksByPriority();
            for (const auto& task : tasks) {
                showTaskDetails(task);
            }
            break;
        }
        case 5: {
            notificationSystem.checkDueDates(taskManager.listAllTasks());
            break;
        }
        case 6: {
            exit(0);
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}