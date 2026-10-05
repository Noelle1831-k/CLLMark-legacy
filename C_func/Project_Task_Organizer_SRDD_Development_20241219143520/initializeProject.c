Project *initializeProject(const char *name, const char *manager) {
    Project *project = (Project *)malloc(sizeof(Project));
    strcpy(project->name, name);
    strcpy(project->manager, manager);
    project->taskCount = 0;
    return project;
}