void display_summary(DailyWaterTracker *tracker) {
    printf("Daily Water Tracker Summary:\n");
    for (int i = 0; i < tracker->user_count; i++) {
        User *user = &tracker->users[i];
        printf("User: %s\n", user->name);
        printf("Total Intake: %d ml\n", get_total_intake(user));
        printf("Goal Met: %s\n", check_goal(user) ? "Yes" : "No");
        display_log(&user->intake_log);
        printf("\n");
    }
}