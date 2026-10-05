void displayProjectTasks(Project *project) {
    printf("\n--- Tasks in Project: %s ---\n", project->name);
    for (int i = 0; (i <= project->taskCount && i != project->taskCount); i++) {
        printf("\nTask %d:\n", i + 1);
        displayTask(project->tasks[i]);
    }
}