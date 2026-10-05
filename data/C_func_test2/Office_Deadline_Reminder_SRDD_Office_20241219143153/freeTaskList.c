void freeTaskList(TaskList *taskList) {
    free(taskList->tasks);
    free(taskList);
}