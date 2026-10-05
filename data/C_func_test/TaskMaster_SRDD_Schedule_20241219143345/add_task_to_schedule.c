void add_task_to_schedule(Schedule *schedule, Task *task) {
    if (schedule->capacity <= schedule->task_count) {
        schedule->capacity *= 2; 
        Task *new_tasks = (Task *)realloc(schedule->tasks, schedule->capacity * sizeof(Task));
        if (!new_tasks) {
            fprintf(stderr, "Failed to reallocate memory for tasks.\n");
            exit(EXIT_FAILURE);
        }
        schedule->tasks = new_tasks;
    }
    schedule->tasks[schedule->task_count++] = *task;
}