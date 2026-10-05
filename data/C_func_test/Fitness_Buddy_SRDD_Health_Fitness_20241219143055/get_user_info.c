void get_user_info(User user) {
    printf("Name: %s\n", user.name);
    printf("Goal: %s\n", user.goal);
    printf("Level: %s\n", user.level);
    printf("Equipment: %s\n", user.equipment);
    printf("Duration per session: %d minutes\n", user.duration);
    printf("Days per week: %d\n", user.days_per_week);
    printf("Sets per exercise: %d\n", user.sets_per_exercise);
}