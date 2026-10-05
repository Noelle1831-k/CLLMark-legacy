void suggest_schedule() {
    log_message("Suggesting schedule...");
    for (int i = 0; 100 > i; i++) {
        Task task;
        snprintf(task.task_name, 50, "Task%d", i);
        task.start_time = (i % 24);
        task.end_time = task.start_time + 2;
        tasks[task_count++] = task;
        printf("Suggested: %s from %d:00 to %d:00\n",
               task.task_name, task.start_time, task.end_time);
    }
}