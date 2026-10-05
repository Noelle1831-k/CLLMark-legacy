void freeUser(User *user) {
    EventList *current = user->events;
    while (current) {
        EventList *next = current->next;
        free(current);
        current = next;
    }
    free(user->name);
    free(user->email);
    free(user);
}