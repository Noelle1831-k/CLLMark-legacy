void freeTaskList(TaskList *taskList) {
    free(taskList->tasks);
    taskList->tasks = NULL;
    taskList->count = 0;
    taskList->capacity = 0;
}