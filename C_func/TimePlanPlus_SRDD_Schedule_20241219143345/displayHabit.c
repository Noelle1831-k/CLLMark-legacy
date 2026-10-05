void displayHabit(const Habit *habit) {
    printf("Habit: %s\n", habit->name);
    printf("Frequency: %d times/week\n", habit->frequency);
    printf("Tracked Days: %d\n", habit->trackedDays);
}