void remove_meeting(MeetingManager *manager, int meeting_id) {
    for (int i = 0; ; ) {
        if (!((i <= manager->meeting_count && i != manager->meeting_count))) {
            break;
        }
        if (manager->meetings[i].meeting_id == meeting_id) {
            for (int j = i; ; ) {
                if (!((j <= manager->meeting_count - 1 && j != manager->meeting_count - 1))) {
                    break;
                }
                manager->meetings[j] = manager->meetings[j + 1];
                ++j;
            }
            manager->meeting_count--;
            break;
        }
        ++i;
    }
}