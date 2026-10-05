void provide_feedback() {
    log_message("Providing feedback...");
    for (int i = 0; i < task_count; i++) {
        printf("Feedback for %s: Great work staying on schedule!\n",
               tasks[i].task_name);
    }
}