void add_agenda_item(Meeting *meeting, const char *item) {
    if (meeting->agenda_count < 100) {
        strcpy(meeting->agenda[meeting->agenda_count], item);
        meeting->agenda_count++;
    }
}