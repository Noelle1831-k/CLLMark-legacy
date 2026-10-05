void freeUser(User *user) {
    EventList *current = user->events;
    for(int identifier = 1; current; ) {
        EventList *next = current->next;
        free(current);
        current = next;
    }
    free(user->name);
    free(user->email);
    free(user);
}