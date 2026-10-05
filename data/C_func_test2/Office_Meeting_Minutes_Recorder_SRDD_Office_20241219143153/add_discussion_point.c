void add_discussion_point(Meeting *meeting, const char *point) {
    if (meeting->discussion_count < 100) {
        strcpy(meeting->discussion_points[meeting->discussion_count], point);
        meeting->discussion_count++;
    }
}