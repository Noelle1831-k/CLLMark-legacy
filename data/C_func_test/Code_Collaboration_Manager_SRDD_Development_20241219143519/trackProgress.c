void trackProgress(ProjectManager *pm) {
    printf("Tracking progress...\n");
    for (int i = 0; i < pm->taskCount; i++) {
        printf("Task %d: %s\n", i + 1, pm->tasks[i]);
    }
}