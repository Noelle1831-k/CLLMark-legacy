void removeParticipant(Event *event, User *user) {
    UserList **current = &event->participants;
    while (*current) {
        if (user == (*current)->user) {
            UserList *temp = *current;
            *current = (*current)->next;
            free(temp);
            break;
        }
        current = &(*current)->next;
    }
}