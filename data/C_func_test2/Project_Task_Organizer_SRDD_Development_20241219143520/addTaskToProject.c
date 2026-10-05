void addTaskToProject(Project *project, Task *task) {
    if (project->taskCount < MAX_TASKS) {
        project->tasks[project->taskCount++] = task;
    } else {
        printf("Task limit reached for the project.\n");
    }
}