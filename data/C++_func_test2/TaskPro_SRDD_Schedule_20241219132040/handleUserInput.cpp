void UIManager::handleUserInput() {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: {
            string title, timeSlot, notes;
            int priority, taskID;
            cout << "Enter Task ID: ";
            cin >> taskID;
            cout << "Enter Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Priority: ";
            cin >> priority;
            cout << "Enter Time Slot: ";
            cin.ignore();
            getline(cin, timeSlot);
            cout << "Enter Notes: ";
            getline(cin, notes);
            taskManager.addTask(Task(taskID, title, priority, timeSlot, notes));
            break;
        }
        case 2: {
            int taskID;
            cout << "Enter Task ID to Delete: ";
            cin >> taskID;
            taskManager.deleteTask(taskID);
            break;
        }
        case 3:
            taskManager.sortTasksByPriority();
            break;
        case 4:
            taskManager.showDailyOverview();
            break;
        case 5:
            taskManager.showCompletedTasks();
            break;
        case 6: {
            int taskID;
            cout << "Enter Task ID to Mark as Completed: ";
            cin >> taskID;
            Task* task = taskManager.findTaskByID(taskID);
            if (task) {
                task->markAsCompleted();
                cout << "Task marked as completed successfully!" << endl;
            } else {
                cout << "Task not found!" << endl;
            }
            break;
        }
        case 7:
            exit(0);
        default:
            cout << "Invalid choice. Try again.\n";
    }
}