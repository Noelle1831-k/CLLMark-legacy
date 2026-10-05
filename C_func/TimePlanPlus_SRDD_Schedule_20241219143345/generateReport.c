void generateReport(const Scheduler *scheduler) {
    printf("\n=== Report ===\n");
    printf("Tasks:\n");
    for (int i = 0; i < scheduler->taskCount; i++) {
        displayTask(&scheduler->tasks[i]);
    }
    printf("\nHabits:\n");
    for (int i = 0; i < scheduler->habitCount; i++) {
        displayHabit(&scheduler->habits[i]);
    }
    printf("\nGoals:\n");
    for (int i = 0; i < scheduler->goalCount; i++) {
        displayGoal(&scheduler->goals[i]);
    }
}