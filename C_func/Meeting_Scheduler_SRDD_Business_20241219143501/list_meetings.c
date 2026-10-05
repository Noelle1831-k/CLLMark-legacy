void list_meetings() {
    if (meeting_count == 0) {
        printf("No meetings scheduled.\n");
        return;
    }
    for (int i = 0; i < meeting_count; i++) {
        printf("\nMeeting %d:\n", i + 1);
        printf("Title: %s\n", meetings[i].title);
        printf("Date: %s\n", meetings[i].date);
        printf("Time: %s\n", meetings[i].time);
        printf("Participants: %s\n", meetings[i].participants);
    }
}