int main() {
    TaskList taskList;
    initTaskList(&taskList);
    int choice;
    do {
        printf("\nTaskPro - Task Management System\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. View Tasks\n");
        printf("4. Schedule Tasks\n");
        printf("5. Exit\n");
        choice = getValidatedChoice();
        switch (choice) {
            case 1:
                addTask(&taskList);
                break;
            case 2:
                removeTask(&taskList);
                break;
            case 3:
                displayTasks(&taskList);
                break;
            case 4:
                scheduleTasks(&taskList);
                break;
            case 5:
                printf("Exiting TaskPro...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    freeTaskList(&taskList);
    return 0;
}