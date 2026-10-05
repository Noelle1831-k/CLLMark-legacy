void showSchedule(Scheduler *scheduler) {
    printf("\n--- Scheduled Tasks ---\n");
    for (int i = 0; i < scheduler->scheduledCount; i++) {
        printf("Task ID: %d\n", scheduler->schedule[i].id);
        printf("Name: %s\n", scheduler->schedule[i].name);
        printf("Priority: %d\n", scheduler->schedule[i].priority);
        printf("Estimated Time: %d minutes\n", scheduler->schedule[i].estimatedTime);
        printf("-----------------------\n");
    }
}