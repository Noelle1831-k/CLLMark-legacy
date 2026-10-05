void viewSchedule() {
    if (task_count == 0) {
        printf("No tasks in the schedule.\n");
        return;
    }
    printf("\n========== Current Schedule ==========\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task %d:\n", i + 1);
        printf("Name: %s\n", tasks[i].name);
        printf("Priority: %d\n", tasks[i].priority);
        printf("Start Time: %s\n", tasks[i].start_time);
        printf("End Time: %s\n", tasks[i].end_time);
        printf("Status: %s\n\n", tasks[i].status);
    }
}