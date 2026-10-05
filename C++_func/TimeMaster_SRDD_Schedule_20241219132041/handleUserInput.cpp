void TimeMaster::handleUserInput(int choice) {
    string name, timeSlot, newName;
    int priority, progress, newPriority, newProgress;
    switch (choice) {
        case 1:
            cout << "Enter task name: ";
            cin >> name;
            cout << "Enter priority: ";
            cin >> priority;
            cout << "Enter time slot: ";
            cin >> timeSlot;
            cout << "Enter progress: ";
            cin >> progress;
            schedule.addTask(Task(name, priority, timeSlot, progress));
            break;
        case 2:
            cout << "Enter task name to remove: ";
            cin >> name;
            schedule.removeTask(name);
            break;
        case 3:
            schedule.displaySchedule();
            break;
        case 4:
            report.generateReport(schedule);
            break;
        case 5:
            cout << "Exiting TimeMaster..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}