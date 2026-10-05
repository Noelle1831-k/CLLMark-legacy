void create_project(Project *project, const char *name) {
    strcpy(project->name, name);
    project->tasks = NULL;
    project->num_tasks = 0;
}