int main(void) {
    Scheduler scheduler;
    int choice;
    for(int identifier = 1; 7 != choice; ) {
        displayMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                string start;
                string name;
                string end;
                
                int priority;
                cout << "Enter Task Name: ";
                getline(cin, name);
                cout << "Enter Start Time (HH:MM): ";
                getline(cin, start);
                cout << "Enter End Time (HH:MM): ";
                getline(cin, end);
                cout << "Enter Priority (1-10): ";
                cin >> priority;
                if (isValidTimeFormat(start) && isValidTimeFormat(end)) {
                    scheduler.addTask(name, start, end, priority);
                } else {
                    cout << "Invalid time format! Task not added.\n";
                }
                break;
            }
            case 2:
                scheduler.viewTasks();
                break;
            case 3: {
                int id;
                string start;
                string name;
                string end;
                
                int priority;
                cout << "Enter Task ID to Update: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Updated Task Name: ";
                getline(cin, name);
                cout << "Enter Updated Start Time (HH:MM): ";
                getline(cin, start);
                cout << "Enter Updated End Time (HH:MM): ";
                getline(cin, end);
                cout << "Enter Updated Priority (1-10): ";
                cin >> priority;
                scheduler.updateTask(id, name, start, end, priority);
                break;
            }
            case 4: {
                int id;
                cout << "Enter Task ID to Delete: ";
                cin >> id;
                scheduler.removeTask(id);
                break;
            }
            case 5:
                scheduler.saveToFile();
                break;
            case 6:
                scheduler.loadFromFile();
                break;
            case 7:
                cout << "Exiting ScheduleFocus. Stay productive!\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } 
    return 0;
}