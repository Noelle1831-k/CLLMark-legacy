void removeTask(TaskList *taskList) {
    if (taskList->count == 0) {
        printf("No tasks to remove.\n");
        return;
    }
    int index;
    while (1) {
        printf("Enter task index to remove (0 to %d): ", taskList->count - 1);
        if (scanf("%d", &index) == 1 && index >= 0 && index < taskList->count) {
            break;
        }
        printf("Invalid index. Please try again.\n");
        while (getchar() != '\n'); 
    }
    for (int i = index; i < taskList->count - 1; i++) {
        taskList->tasks[i] = taskList->tasks[i + 1];
    }
    taskList->count--;
}