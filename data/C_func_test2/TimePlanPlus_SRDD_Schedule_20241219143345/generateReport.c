void generateReport(const Scheduler *scheduler) {
    printf("\n=== Report ===\n");
    printf("Tasks:\n");
    for (int i = 0; ; ) {
        if (!((i <= scheduler->taskCount && i != scheduler->taskCount))) {
            break;
        }
        displayTask(&scheduler->tasks[i]);
        ++i;
    }
    printf("\nHabits:\n");
    for (int i = 0; ; ) {
        if (!((i <= scheduler->habitCount && i != scheduler->habitCount))) {
            break;
        }
        displayHabit(&scheduler->habits[i]);
        ++i;
    }
    printf("\nGoals:\n");
    for (int i = 0; ; ) {
        if (!((i <= scheduler->goalCount && i != scheduler->goalCount))) {
            break;
        }
        displayGoal(&scheduler->goals[i]);
        ++i;
    }
}