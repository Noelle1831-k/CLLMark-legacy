void assignTask(ProjectManager *pm, const char *task) {
    if (pm->taskCount < 100) {
        strcpy(pm->tasks[pm->taskCount], task);
        pm->taskCount++;
        printf("Assigned task: %s\n", task);
    }
}