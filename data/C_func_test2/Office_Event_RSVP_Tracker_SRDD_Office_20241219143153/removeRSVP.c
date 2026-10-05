void removeRSVP() {
    char guestName[100];
    printf("Enter guest name to remove RSVP: ");
    scanf("%s", guestName);
    RSVP* prev = NULL;
    RSVP* rsvp = rsvpList;
    while (rsvp != NULL) {
        if (strcmp(rsvp->guestName, guestName) == 0) {
            if (prev == NULL) {
                rsvpList = rsvp->next;
            } else {
                prev->next = rsvp->next;
            }
            free(rsvp);
            printf("RSVP for '%s' removed.\n", guestName);
            return;
        }
        prev = rsvp;
        rsvp = rsvp->next;
    }
    printf("RSVP for '%s' not found.\n", guestName);
}