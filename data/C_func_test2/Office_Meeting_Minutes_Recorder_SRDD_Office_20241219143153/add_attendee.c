void add_attendee(Meeting *meeting, const char *attendee) {
    if (meeting->attendee_count < 100) {
        strcpy(meeting->attendees[meeting->attendee_count], attendee);
        meeting->attendee_count++;
    }
}