void joinEvent(User *user, Event *event) {
    EventList *newNode = (EventList *)malloc(sizeof(EventList));
    newNode->event = event;
    newNode->next = user->events;
    user->events = newNode;
    addParticipant(event, user);
}