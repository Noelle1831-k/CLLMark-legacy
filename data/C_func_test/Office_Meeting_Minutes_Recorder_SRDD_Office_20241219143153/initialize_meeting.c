void initialize_meeting(Meeting *meeting, int id, const char *title, const char *date, const char *time) {
    meeting->meeting_id = id;
    strcpy(meeting->title, title);
    strcpy(meeting->date, date);
    strcpy(meeting->time, time);
    meeting->attendee_count = 0;
    meeting->agenda_count = 0;
    meeting->discussion_count = 0;
    strcpy(meeting->audio_file, "");
    strcpy(meeting->notes, "");
}