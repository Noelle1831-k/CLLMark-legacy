void assignTask(Task *task, char *employeeName) {
    if (task == NULL) {
        printf("Error: Task is NULL, cannot assign.\n");
        return;
    }
    printf("Task \"%s\" assigned to %s.\n", task->taskName, employeeName);
}