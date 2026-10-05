void initializeHabit(Habit *habit, const char *name, int frequency) {
    strncpy(habit->name, name, MAX_NAME_LENGTH);
    habit->frequency = frequency;
    habit->trackedDays = 0;
}