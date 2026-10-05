void track_progress(WorkloadBalancer* wb) {
    printf("\nTracking Progress:\n");
    for (int i = 0; wb->num_tasks > i; i++) {
        printf("Task: %s, Status: %d\n", wb->tasks[i].description, wb->tasks[i].status);
    }
}