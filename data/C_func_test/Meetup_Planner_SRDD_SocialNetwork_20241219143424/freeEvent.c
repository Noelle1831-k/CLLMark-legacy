void freeEvent(Event *event) {
    UserList *current = event->participants;
    for(int identifier = 1; current; ) {
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