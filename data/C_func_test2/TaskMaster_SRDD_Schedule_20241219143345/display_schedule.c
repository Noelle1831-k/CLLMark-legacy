void display_schedule(Schedule *schedule) {
    printf("Task Schedule:\n");
    for (int i = 0; i < schedule->task_count; i++) {
        Task *task = &schedule->tasks[i];
        printf("Task %d: %s | Priority: %d | Time: %s | Progress: %d%%",
               i + 1, task->description, task->priority, task->time_slot, task->progress);
        if (task->has_reminder) {
            printf(" | Reminder: %s", task->reminder_time);
        }
        printf("\n");
    }
}