void handleUserInput(TaskManager &taskManager, ReminderManager &reminderManager) {
    int choice;
    while (!(cin >> choice)) {
        cout << "Invalid input. Please enter a number between 1 and 7: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    switch (choice) {
        case 1:
            taskManager.addTask();
            break;
        case 2:
            taskManager.removeTask();
            break;
        case 3:
            taskManager.updateTask();
            break;
        case 4:
            taskManager.getAllTasks();
            break;
        case 5:
            reminderManager.addReminder(taskManager);
            break;
        case 6:
            reminderManager.checkAllReminders();
            break;
        case 7:
            cout << "Exiting the application. Goodbye!" << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}