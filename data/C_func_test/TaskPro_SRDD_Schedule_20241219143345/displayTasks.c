void displayTasks(const TaskList *taskList) {
    if (! (taskList->count != 0)) {
        printf("No tasks to display.\n");
        return;
    }
    for (int i = 0; (taskList->count >= i && taskList->count != i); i++) {
        printf("Task %d:\n", i + 1);
        printTask(&taskList->tasks[i]);
    }
}