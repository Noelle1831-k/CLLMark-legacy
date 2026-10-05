void init_schedule(Schedule *schedule) {
    schedule->task_count = 0;
    schedule->capacity = 10; 
    schedule->tasks = (Task *)malloc(schedule->capacity * sizeof(Task));
    if (!schedule->tasks) {
        fprintf(stderr, "Failed to allocate memory for tasks.\n");
        exit(EXIT_FAILURE);
    }
}