void remove_task(Schedule *schedule, const char *title) {
    Task *current = schedule->head;
    Task *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (prev == NULL) {
                schedule->head = current->next;
            } else {
                prev->next = current->next;
            }
            delete_task(current);
            printf("Task '%s' removed successfully.\n", title);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Task '%s' not found.\n", title);
}