Task* createTask(char *taskName, char *description) {
    Task *newTask = (Task *)malloc(sizeof(Task));
    if (newTask == NULL) {
        printf("Memory allocation failed. Task creation unsuccessful.\n");
        return NULL;
    }
    newTask->taskId = rand() % 1000;  
    strcpy(newTask->taskName, taskName);
    strcpy(newTask->description, description);
    newTask->next = NULL;
    return newTask;
}