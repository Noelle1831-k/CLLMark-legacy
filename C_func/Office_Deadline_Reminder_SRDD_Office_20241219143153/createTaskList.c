TaskList* createTaskList() {
    TaskList *taskList = (TaskList*)malloc(sizeof(TaskList));
    taskList->tasks = (Task*)malloc(INITIAL_CAPACITY * sizeof(Task));
    taskList->size = 0;
    taskList->capacity = INITIAL_CAPACITY;
    return taskList;
}