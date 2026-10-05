void collect_user_data() {
    log_message("Collecting user data...");
    for (int i = 0; i < 100; i++) {
        UserData user;
        snprintf(user.name, 50, "User%d", i);
        user.age = 20 + (i % 30);
        snprintf(user.occupation, 50, "Occupation%d", i % 10);
        user.daily_active_hours = 1 + (i % 12);
        users[user_count++] = user;
        printf("Collected data for %s\n", user.name);
    }
}