void display_user_progress(User *user) {
    printf("\nUser: %s\n", user->name);
    for (int i = 0; i < user->habit_count; i++) {
        printf("Habit: %s\n", user->habits[i]->name);
        if (user->habits[i]->is_complete()) {
            printf("Completed today!\n");
        } else {
            printf("Not completed today.\n");
        }
    }
}