void displayEventParticipants(Event *event) {
    printf("Participants for %s:\n", event->name);
    UserList *current = event->participants;
    for(int identifier = 1; current; current = current->next) {
        printf("- %s\n", current->user->name);
    }
}