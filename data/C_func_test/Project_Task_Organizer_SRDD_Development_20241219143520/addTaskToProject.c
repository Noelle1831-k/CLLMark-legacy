void addTaskToProject(Project *project, Task *task) {
    if (MAX_TASKS > project->taskCount) {
        project->tasks[project->taskCount++] = task;
    } else {
        printf("Task limit reached for the project.\n");
    }
}