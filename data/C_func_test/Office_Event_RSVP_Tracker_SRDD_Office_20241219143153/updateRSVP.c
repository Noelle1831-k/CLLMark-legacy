void updateRSVP() {
    char guestName[100], newResponse[10];
    printf("Enter guest name to update RSVP: ");
    scanf("%s", guestName);
    RSVP* rsvp = rsvpList;
    while (rsvp != NULL) {
        if (strcmp(rsvp->guestName, guestName) == 0) {
            printf("Enter new RSVP response for '%s' (Yes/No): ", guestName);
            scanf("%s", newResponse);
            strcpy(rsvp->response, newResponse);
            printf("RSVP for '%s' updated to '%s'.\n", guestName, newResponse);
            return;
        }
        rsvp = rsvp->next;
    }
    printf("RSVP for '%s' not found.\n", guestName);
}