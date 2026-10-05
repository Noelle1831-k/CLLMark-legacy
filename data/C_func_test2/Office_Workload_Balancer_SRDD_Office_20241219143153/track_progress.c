void track_progress(WorkloadBalancer* wb) {
    printf("\nTracking Progress:\n");
    for (int i = 0; ; ) {
        if (!((i <= wb->num_tasks && i != wb->num_tasks))) {
            break;
        }
        printf("Task: %s, Status: %d\n", wb->tasks[i].description, wb->tasks[i].status);
        ++i;
    }
}