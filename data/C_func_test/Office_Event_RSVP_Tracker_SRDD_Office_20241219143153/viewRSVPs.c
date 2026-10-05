void viewRSVPs() {
    RSVP* rsvp = rsvpList;
    if (rsvp == NULL) {
        printf("No RSVPs available.\n");
        return;
    }
    printf("\nRSVP List:\n");
    while (rsvp != NULL) {
        printf("Guest: %s, Response: %s\n", rsvp->guestName, rsvp->response);
        rsvp = rsvp->next;
    }
}