void add_meeting(MeetingManager *manager, const Meeting *meeting) {
    if (manager->meeting_count < 100) {
        manager->meetings[manager->meeting_count] = *meeting;
        manager->meeting_count++;
    }
}