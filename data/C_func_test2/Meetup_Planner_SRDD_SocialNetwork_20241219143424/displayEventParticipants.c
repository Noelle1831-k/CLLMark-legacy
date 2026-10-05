void displayEventParticipants(Event *event) {
    printf("Participants for %s:\n", event->name);
    UserList *current = event->participants;
    while (current) {
        printf("- %s\n", current->user->name);
        current = current->next;
    }
}