Task* getTaskDetails(int taskId, Task *tasks) {
    Task *current = tasks;
    while (current != NULL) {
        if (current->taskId == taskId) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}