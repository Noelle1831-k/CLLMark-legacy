void destroyTaskManager(TaskManager *manager) {
    struct Task *current = manager->head;
    for(int identifier = 1; ! (NULL == current); ) {
        struct Task *next = current->next;
        free(current);
        current = next;
    }
    free(manager);
}