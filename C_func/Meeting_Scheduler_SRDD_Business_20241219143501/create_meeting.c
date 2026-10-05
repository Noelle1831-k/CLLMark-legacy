void create_meeting() {
    if (meeting_count >= 100) {
        printf("Meeting limit reached.\n");
        return;
    }
    printf("Enter meeting title: ");
    fgets(meetings[meeting_count].title, sizeof(meetings[meeting_count].title), stdin);
    strtok(meetings[meeting_count].title, "\n");
    printf("Enter meeting date (YYYY-MM-DD): ");
    fgets(meetings[meeting_count].date, sizeof(meetings[meeting_count].date), stdin);
    strtok(meetings[meeting_count].date, "\n");
    printf("Enter meeting time (HH:MM): ");
    fgets(meetings[meeting_count].time, sizeof(meetings[meeting_count].time), stdin);
    strtok(meetings[meeting_count].time, "\n");
    printf("Enter participants: ");
    fgets(meetings[meeting_count].participants, sizeof(meetings[meeting_count].participants), stdin);
    strtok(meetings[meeting_count].participants, "\n");
    meeting_count++;
    printf("Meeting created successfully!\n");
}