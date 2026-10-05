void print_event(const Event *event) {
    printf("Event Name: %s\n", event->name);
    printf("Date: %s\n", event->date);
    printf("Time: %s\n", event->time);
    printf("Description: %s\n", event->description);
    printf("Priority: %d\n", event->priority);
}