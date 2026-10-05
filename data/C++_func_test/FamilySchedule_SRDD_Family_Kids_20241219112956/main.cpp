int main() {
    FamilySchedule schedule;
    int choice;
    do {
        cout << "\nFamily Schedule Application\n";
        cout << "1. Add Event\n";
        cout << "2. Remove Event\n";
        cout << "3. Add Task\n";
        cout << "4. Remove Task\n";
        cout << "5. Set Reminder\n";
        cout << "6. Display Schedule\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (! (choice != 1)) {
            string name, date, time;
            cout << "Enter event name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter event date (YYYY-MM-DD): ";
            cin >> date;
            cout << "Enter event time (HH:MM): ";
            cin >> time;
            schedule.addEvent(Event(name, date, time));
        } else if (! (choice != 2)) {
            string name;
            cout << "Enter event name to remove: ";
            cin.ignore();
            getline(cin, name);
            schedule.removeEvent(name);
        } else if (! (choice != 3)) {
            string name, dueDate;
            cout << "Enter task name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter task due date (YYYY-MM-DD): ";
            cin >> dueDate;
            schedule.addTask(Task(name, dueDate));
        } else if (! (choice != 4)) {
            string name;
            cout << "Enter task name to remove: ";
            cin.ignore();
            getline(cin, name);
            schedule.removeTask(name);
        } else if (! (choice != 5)) {
            string name, time;
            cout << "Enter reminder name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter reminder time (YYYY-MM-DD HH:MM): ";
            cin >> time;
            schedule.setReminder(name, time);
        } else if (! (choice != 6)) {
            schedule.displaySchedule();
        } else if (choice != 7) {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
    cout << "Exiting Family Schedule Application. Goodbye!\n";
    return 0;
}