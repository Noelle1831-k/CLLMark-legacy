void handleOption(int option) {
    static vector<Schedule> schedules;
    static NotificationManager notificationManager;
    switch (option) {
        case 1: {
            string scheduleName;
            cout << "Enter schedule name: ";
            cin.ignore();
            getline(cin, scheduleName);
            schedules.emplace_back(Schedule(schedules.size(), scheduleName));
            cout << "Schedule created successfully.\n";
            break;
        }
        case 2: {
            int scheduleID;
            string taskName, assignedTo;
            string deadline;
            cout << "Enter schedule ID: ";
            cin >> scheduleID;
            if (scheduleID >= 0 && scheduleID < schedules.size()) {
                cout << "Enter task name: ";
                cin.ignore();
                getline(cin, taskName);
                cout << "Enter assigned to: ";
                getline(cin, assignedTo);
                cout << "Enter deadline (YYYY-MM-DD): ";
                getline(cin, deadline);
                schedules[scheduleID].addTask(Task(schedules[scheduleID].getTaskCount(), taskName, deadline, assignedTo));
                cout << "Task added successfully.\n";
            } else {
                cout << "Invalid schedule ID.\n";
            }
            break;
        }
        case 3: {
            int scheduleID;
            cout << "Enter schedule ID: ";
            cin >> scheduleID;
            if (scheduleID >= 0 && scheduleID < schedules.size()) {
                schedules[scheduleID].getScheduleDetails();
            } else {
                cout << "Invalid schedule ID.\n";
            }
            break;
        }
        case 4: {
            int scheduleID, taskID;
            string status;
            cout << "Enter schedule ID: ";
            cin >> scheduleID;
            if (scheduleID >= 0 && scheduleID < schedules.size()) {
                cout << "Enter task ID: ";
                cin >> taskID;
                cout << "Enter new status: ";
                cin.ignore();
                getline(cin, status);
                schedules[scheduleID].updateTask(taskID, status);
                cout << "Task updated successfully.\n";
            } else {
                cout << "Invalid schedule ID.\n";
            }
            break;
        }
        case 5: {
            notificationManager.getNotifications();
            break;
        }
        case 0:
            cout << "Exiting application.\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
    }
}