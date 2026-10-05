void remove_meeting(MeetingManager *manager, int meeting_id) {
    for (int i = 0; i < manager->meeting_count; i++) {
        if (manager->meetings[i].meeting_id == meeting_id) {
            for (int j = i; j < manager->meeting_count - 1; j++) {
                manager->meetings[j] = manager->meetings[j + 1];
            }
            manager->meeting_count--;
            break;
        }
    }
}