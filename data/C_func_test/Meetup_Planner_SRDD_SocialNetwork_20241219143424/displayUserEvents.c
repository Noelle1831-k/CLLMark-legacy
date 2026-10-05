void displayUserEvents(User *user) {
    printf("Events for %s:\n", user->name);
    EventList *current = user->events;
    while (current) {
        printf("- %s on %s at %s\n", current->event->name, current->event->date, current->event->time);
        current = current->next;
    }
}