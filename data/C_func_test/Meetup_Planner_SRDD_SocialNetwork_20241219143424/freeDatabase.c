void freeDatabase(Database *db) {
    UserList *currentUser = db->users;
    while (currentUser) {
        UserList *nextUser = currentUser->next;
        freeUser(currentUser->user);
        free(currentUser);
        currentUser = nextUser;
    }
    EventList *currentEvent = db->events;
    while (currentEvent) {
        EventList *nextEvent = currentEvent->next;
        freeEvent(currentEvent->event);
        free(currentEvent);
        currentEvent = nextEvent;
    }
    free(db);
}