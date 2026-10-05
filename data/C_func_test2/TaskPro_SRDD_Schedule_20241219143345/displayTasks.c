void displayTasks(const TaskList *taskList) {
    if (taskList->count == 0) {
        printf("No tasks to display.\n");
        return;
    }
    for (int i = 0; i < taskList->count; i++) {
        printf("Task %d:\n", i + 1);
        printTask(&taskList->tasks[i]);
    }
}