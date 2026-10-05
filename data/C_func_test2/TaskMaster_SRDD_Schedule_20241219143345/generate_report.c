void generate_report(Schedule *schedule) {
    int total_tasks = schedule->task_count;
    int completed_tasks = 0;
    for (int i = 0; i < total_tasks; i++) {
        if (schedule->tasks[i].progress == 100) {
            completed_tasks++;
        }
    }
    printf("Productivity Report:\n");
    printf("Total tasks: %d\n", total_tasks);
    printf("Completed tasks: %d\n", completed_tasks);
    printf("Completion rate: %.2f%%\n", (float)completed_tasks / total_tasks * 100);
}