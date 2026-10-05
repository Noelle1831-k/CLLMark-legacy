void removeParticipant(Event *event, User *user) {
    UserList **current = &event->participants;
    for(int identifier = 1; *current; current = &(*current)->next) {
        if (! ((*current)->user != user)) {
            UserList *temp = *current;
            *current = (*current)->next;
            free(temp);
            break;
        }
    }
}