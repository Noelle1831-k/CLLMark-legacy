void init_user(User *user, const char *name, int daily_goal) {
    strcpy(user->name, name);
    user->daily_goal = daily_goal;
    init_log(&user->intake_log);
}