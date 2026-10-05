void add_user(DailyWaterTracker *tracker, User *user) {
    if (tracker->user_count < 100) {
        tracker->users[tracker->user_count++] = *user;
    }
}