void display_stats(int daily_step_count) {
    printf("Today's step count: %d\n", daily_step_count);
    if (daily_step_count >= 10000) {
        printf("Great job! You've reached your daily goal!\n");
    } else {
        printf("Keep going! You're %d steps away from your goal.\n", 10000 - daily_step_count);
    }
}