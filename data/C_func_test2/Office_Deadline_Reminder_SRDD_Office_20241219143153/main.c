int main() {
    int choice;
    TaskList *taskList = createTaskList();
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                addTask(taskList);
                break;
            case 2:
                removeTask(taskList);
                break;
            case 3:
                displayTasks(taskList);
                break;
            case 4:
                setDeadline(taskList);
                break;
            case 5:
                checkReminders(taskList);
                break;
            case 6:
                markTaskAsCompleted(taskList);
                break;
            case 7:
                printf("Exiting...\n");
                freeTaskList(taskList);
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}