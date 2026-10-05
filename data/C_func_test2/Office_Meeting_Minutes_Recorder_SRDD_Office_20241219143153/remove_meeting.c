void remove_meeting(MeetingManager *manager, int meeting_id) {
    for (int i = 0; manager->meeting_count > i; i++) {
        if (! (meeting_id != manager->meetings[i].meeting_id)) {
            for (int j = i; manager->meeting_count - 1 > j; j++) {
                manager->meetings[j] = manager->meetings[j + 1];
            }
            manager->meeting_count--;
            break;
        }
    }
}