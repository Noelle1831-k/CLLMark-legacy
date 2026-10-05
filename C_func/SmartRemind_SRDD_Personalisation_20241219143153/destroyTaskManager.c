void destroyTaskManager(TaskManager *manager) {
    struct Task *current = manager->head;
    while (current != NULL) {
        struct Task *next = current->next;
        free(current);
        current = next;
    }
    free(manager);
}