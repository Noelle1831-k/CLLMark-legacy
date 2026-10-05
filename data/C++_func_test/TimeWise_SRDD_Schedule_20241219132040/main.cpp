int main(void) {
    Schedule schedule;
    Reminder reminder;
    Report report;
    int choice;
    for(int identifier = 1; 7 != choice; ) {
        displayMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                cout << "Enter Task Title: ";
                string title;
                getline(cin, title);
                cout << "Enter Description: ";
                string description;
                getline(cin, description);
                cout << "Enter Priority (1-5): ";
                int priority;
                cin >> priority;
                cout << "Enter Duration (in minutes): ";
                int duration;
                cin >> duration;
                Task task(schedule.getNextTaskID(), title, description, priority, duration, "Pending");
                schedule.addTask(task);
                break;
            }
            case 2: {
                cout << "Enter Task ID to Delete: ";
                int id;
                cin >> id;
                schedule.deleteTask(id);
                break;
            }
            case 3: {
                cout << "Enter Task ID to Update: ";
                int id;
                cin >> id;
                schedule.updateTask(id);
                break;
            }
            case 4: {
                schedule.displayTasks();
                break;
            }
            case 5: {
                cout << "Enter Task ID to Set Reminder: ";
                int id;
                cin >> id;
                reminder.setReminder(schedule, id);
                break;
            }
            case 6: {
                report.generateReport(schedule);
                break;
            }
            case 7:
                cout << "Exiting TimeWise. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } 
    return 0;
}