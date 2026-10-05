void *track_user_behavior(void *arg) {
    while (1) {
        char *user_activity = monitor_user_activity();
        if (user_activity) {
            int behavior_score = analyze_user_behavior(user_activity);
            if (behavior_score > 0) {
                raise_alert("Suspicious User Behavior", behavior_score, user_activity);
            }
            free(user_activity);
        }
    }
    return NULL;
}