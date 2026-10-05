void displayUserEvents(User *user) {
    printf("Events for %s:\n", user->name);
    EventList *current = user->events;
    for(int identifier = 1; current; current = current->next) {
        printf("- %s on %s at %s\n", current->event->name, current->event->date, current->event->time);
    }
}