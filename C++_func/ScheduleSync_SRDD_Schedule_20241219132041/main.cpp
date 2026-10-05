int main() {
    Schedule schedule;
    Reminder reminder;
    Report report;
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        if (choice == 1) {
            string name, timeSlot;
            int priority;
            cout << "Enter task name: ";
            cin >> name;
            cout << "Enter priority (1-5): ";
            cin >> priority;
            cout << "Enter time slot (e.g., 10:00-11:00): ";
            cin >> timeSlot;
            Task task(name, priority, timeSlot);
            schedule.addTask(task);
        } else if (choice == 2) {
            string name;
            cout << "Enter task name to remove: ";
            cin >> name;
            schedule.removeTask(name);
        } else if (choice == 3) {
            schedule.displaySchedule();
        } else if (choice == 4) {
            string name, time;
            cout << "Enter task name for reminder: ";
            cin >> name;
            cout << "Enter reminder time (e.g., 09:00): ";
            cin >> time;
            reminder.setReminder(name, time);
        } else if (choice == 5) {
            report.generateReport(schedule);
            report.displayReport();
        } else if (choice == 6) {
            schedule.syncSchedule();
        } else if (choice == 7) {
            cout << "Exiting ScheduleSync. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}