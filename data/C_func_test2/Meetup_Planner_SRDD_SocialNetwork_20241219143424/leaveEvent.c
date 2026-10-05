void leaveEvent(User *user, Event *event) {
    EventList **current = &user->events;
    while (*current) {
        if ((*current)->event == event) {
            EventList *temp = *current;
            *current = (*current)->next;
            free(temp);
            break;
        }
        current = &(*current)->next;
    }
    removeParticipant(event, user);
}