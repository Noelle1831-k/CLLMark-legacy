int main(int argc, char *argv[]) {
    Schedule schedule;
    int choice;
    while (true) {
        displayMenu();
        printf("Enter your choice: ");
        cin >> choice;
        switch (choice) {
            case 1: {
                string title, description, deadline;
                double timeAllocated;
                printf("Enter task title: ");
                cin.ignore();
                getline(cin, title);
                printf("Enter task description: ");
                getline(cin, description);
                printf("Enter task deadline (YYYY-MM-DD): ");
                cin >> deadline;
                printf("Enter time allocated (in hours): ");
                cin >> timeAllocated;
                schedule.addTask(title, description, deadline, timeAllocated);
                break;
            }
            case 2: {
                int id;
                printf("Enter task ID to remove: ");
                cin >> id;
                schedule.removeTask(id);
                break;
            }
            case 3:
                schedule.displayTasks();
                break;
            case 4:
                schedule.generateReport();
                break;
            case 5:
                printf("Exiting TimePlan. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}