void track_habit(User *user) {
    int habit_id;
    printf("Enter habit ID (1 to %d): ", user->habit_count);
    scanf("%d", &habit_id);
    if (habit_id < 1 || habit_id > user->habit_count) {
        printf("Invalid habit ID.\n");
        return;
    }
    Habit *habit = user->habits[habit_id - 1];
    habit->mark_complete();
    printf("Habit %s marked as complete!\n", habit->name);
}