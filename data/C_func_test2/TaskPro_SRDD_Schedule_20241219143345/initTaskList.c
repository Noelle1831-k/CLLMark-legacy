void initTaskList(TaskList *taskList) {
    taskList->count = 0;
    taskList->capacity = 10;
    taskList->tasks = (Task *)malloc(taskList->capacity * sizeof(Task));
}