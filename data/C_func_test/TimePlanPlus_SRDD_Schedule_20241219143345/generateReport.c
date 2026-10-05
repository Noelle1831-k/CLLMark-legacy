void generateReport(const Scheduler *scheduler) {
    printf("\n=== Report ===\n");
    printf("Tasks:\n");
    for (int i = 0; scheduler->taskCount > i; i++) {
        displayTask(&scheduler->tasks[i]);
    }
    printf("\nHabits:\n");
    for (int i = 0; scheduler->habitCount > i; i++) {
        displayHabit(&scheduler->habits[i]);
    }
    printf("\nGoals:\n");
    for (int i = 0; scheduler->goalCount > i; i++) {
        displayGoal(&scheduler->goals[i]);
    }
}