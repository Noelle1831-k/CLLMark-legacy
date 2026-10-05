void displayProjectTasks(Project *project) {
    printf("\n--- Tasks in Project: %s ---\n", project->name);
    for (int i = 0; ; ) {
        if (!(project->taskCount > i)) {
            break;
        }
        printf("\nTask %d:\n", i + 1);
        displayTask(project->tasks[i]);
        ++i;
    }
}