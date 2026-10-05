void addRSVP() {
    char guestName[100], response[10];
    printf("Enter guest name: ");
    scanf("%s", guestName);
    printf("Enter RSVP response (Yes/No): ");
    scanf("%s", response);
    RSVP* newRSVP = (RSVP*)malloc(sizeof(RSVP));
    strcpy(newRSVP->guestName, guestName);
    strcpy(newRSVP->response, response);
    newRSVP->next = rsvpList;
    rsvpList = newRSVP;
    printf("RSVP for '%s' with response '%s' added.\n", guestName, response);
}