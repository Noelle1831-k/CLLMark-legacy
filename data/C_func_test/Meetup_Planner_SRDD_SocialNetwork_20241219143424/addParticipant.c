void addParticipant(Event *event, User *user) {
    UserList *newNode = (UserList *)malloc(sizeof(UserList));
    newNode->user = user;
    newNode->next = event->participants;
    event->participants = newNode;
}