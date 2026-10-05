void saveDataToFile(Project *project, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(file, "Project: %s\n", project->name);
    fprintf(file, "Manager: %s\n", project->manager);
    fprintf(file, "TaskCount: %d\n", project->taskCount);
    for (int i = 0; i < project->taskCount; i++) {
        fprintf(file, "Task %d: %s | %s | %s | %s\n", i + 1, project->tasks[i]->name,
                project->tasks[i]->description, project->tasks[i]->assignee, project->tasks[i]->status);
    }
    fclose(file);
}