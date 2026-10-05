void list_meetings(const MeetingManager *manager) {
    for (int i = 0; i < manager->meeting_count; i++) {
        printf("Meeting ID: %d\n", manager->meetings[i].meeting_id);
        printf("Title: %s\n", manager->meetings[i].title);
        printf("Date: %s\n", manager->meetings[i].date);
        printf("Time: %s\n", manager->meetings[i].time);
        printf("Attendees: ");
        for (int j = 0; j < manager->meetings[i].attendee_count; j++) {
            printf("%s ", manager->meetings[i].attendees[j]);
        }
        printf("\n");
        printf("Agenda: ");
        for (int j = 0; j < manager->meetings[i].agenda_count; j++) {
            printf("%s ", manager->meetings[i].agenda[j]);
        }
        printf("\n");
        printf("Discussion Points: ");
        for (int j = 0; j < manager->meetings[i].discussion_count; j++) {
            printf("%s ", manager->meetings[i].discussion_points[j]);
        }
        printf("\n");
        printf("Audio File: %s\n", manager->meetings[i].audio_file);
        printf("Notes: %s\n", manager->meetings[i].notes);
        printf("\n");
    }
}