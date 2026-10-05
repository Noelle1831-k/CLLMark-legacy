void freeTaskList(Task *tasks) {
    Task *current = tasks;
    while (current != NULL) {
        Task *next = current->next;
        free(current);
        current = next;
    }
}