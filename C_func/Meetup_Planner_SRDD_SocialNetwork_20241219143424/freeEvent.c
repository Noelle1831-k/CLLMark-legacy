void freeEvent(Event *event) {
    UserList *current = event->participants;
    while (current) {
        UserList *next = current->next;
        free(current);
        current = next;
    }
    free(event->name);
    free(event->date);
    free(event->time);
    free(event->location);
    free(event->interest);
    free(event);
}