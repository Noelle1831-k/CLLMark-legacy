Meeting* get_meeting(MeetingManager *manager, int meeting_id) {
    for (int i = 0; i < manager->meeting_count; i++) {
        if (manager->meetings[i].meeting_id == meeting_id) {
            return &manager->meetings[i];
        }
    }
    return NULL;
}