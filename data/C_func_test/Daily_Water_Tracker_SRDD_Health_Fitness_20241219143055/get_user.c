User* get_user(DailyWaterTracker *tracker, const char *name) {
    for (int i = 0; i < tracker->user_count; i++) {
        if (strcmp(tracker->users[i].name, name) == 0) {
            return &tracker->users[i];
        }
    }
    return NULL;
}