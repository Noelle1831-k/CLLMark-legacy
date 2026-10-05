void listTasks(TaskList *taskList) {
    if (taskList->count == 0) {
        printf("No tasks available.\n");
        return;
    }
    printf("\n=== Task List ===\n");
    for (int i = 0; i < taskList->count; i++) {
        printf("ID: %d, Name: %s, Priority: %d\n", taskList->tasks[i].id, taskList->tasks[i].name, taskList->tasks[i].priority);
    }
}