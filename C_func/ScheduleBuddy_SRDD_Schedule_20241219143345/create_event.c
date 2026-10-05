Event *create_event(const char *name, const char *date, const char *time, const char *description, int priority) {
    Event *event = (Event *)malloc(sizeof(Event));
    if (event == NULL) {
        fprintf(stderr, "Memory allocation failed for Event.\n");
        return NULL;
    }
    strncpy(event->name, name, sizeof(event->name) - 1);
    event->name[sizeof(event->name) - 1] = '\0';
    strncpy(event->date, date, sizeof(event->date) - 1);
    event->date[sizeof(event->date) - 1] = '\0';
    strncpy(event->time, time, sizeof(event->time) - 1);
    event->time[sizeof(event->time) - 1] = '\0';
    strncpy(event->description, description, sizeof(event->description) - 1);
    event->description[sizeof(event->description) - 1] = '\0';
    event->priority = priority;
    return event;
}