void removeTask(TaskManager *manager, const char *description) {
    struct Task *current = manager->head;
    struct Task *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->description, description) == 0) {
            if (previous == NULL) {
                manager->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}