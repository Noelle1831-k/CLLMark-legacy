void addEvent(Database *db, Event *event) {
    EventList *newNode = (EventList *)malloc(sizeof(EventList));
    newNode->event = event;
    newNode->next = db->events;
    db->events = newNode;
}