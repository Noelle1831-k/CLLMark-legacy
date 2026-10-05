User create_user(char *name, char *goal, char *level, char *equipment, int duration, int days_per_week, int sets_per_exercise) {
    User user;
    strcpy(user.name, name);
    strcpy(user.goal, goal);
    strcpy(user.level, level);
    strcpy(user.equipment, equipment);
    user.duration = duration;
    user.days_per_week = days_per_week;
    user.sets_per_exercise = sets_per_exercise;
    return user;
}