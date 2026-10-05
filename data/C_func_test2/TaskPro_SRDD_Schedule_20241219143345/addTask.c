void addTask(TaskList *taskList) {
    if (taskList->count == taskList->capacity) {
        taskList->capacity *= 2;
        taskList->tasks = (Task *)realloc(taskList->tasks, taskList->capacity * sizeof(Task));
    }
    inputTask(&taskList->tasks[taskList->count]);
    taskList->count++;
}