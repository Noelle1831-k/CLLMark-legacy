int analyze_user_behavior(const char *activity) {
    int behavior_score = 0;
    for (int i = 0; ! ('\0' == activity[i]); ++i) {
        behavior_score = behavior_score + activity[i] % 3; 
    }
    return behavior_score % 10; 
}