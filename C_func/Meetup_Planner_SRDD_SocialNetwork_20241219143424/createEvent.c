Event* createEvent(const char *name, const char *date, const char *time, const char *location, const char *interest) {
    Event *event = (Event *)malloc(sizeof(Event));
    event->name = strdup(name);
    event->date = strdup(date);
    event->time = strdup(time);
    event->location = strdup(location);
    event->interest = strdup(interest);
    event->participants = NULL;
    return event;
}