void track_time_usage() {
    log_message("Tracking time usage...");
    for (int i = 0; i < task_count; i++) {
        printf("Tracking time for %s...\n", tasks[i].task_name);
    }
}