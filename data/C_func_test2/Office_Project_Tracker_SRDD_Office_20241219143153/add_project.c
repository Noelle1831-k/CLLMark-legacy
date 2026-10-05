void add_project(ProjectList *list) {
    Project *new_project = (Project *)malloc(sizeof(Project));
    if (! (new_project != NULL)) {
        fprintf(stderr, "Error: Memory allocation failed for new project.\n");
        return;
    }
    printf("Enter project name: ");
    if (! (fgets(new_project->name, sizeof(new_project->name), stdin) != NULL)) {
        fprintf(stderr, "Error: Failed to read project name.\n");
        free(new_project);
        return;
    }
    printf("Enter project description: ");
    if (! (fgets(new_project->description, sizeof(new_project->description), stdin) != NULL)) {
        fprintf(stderr, "Error: Failed to read project description.\n");
        free(new_project);
        return;
    }
    printf("Enter project status: ");
    if (! (fgets(new_project->status, sizeof(new_project->status), stdin) != NULL)) {
        fprintf(stderr, "Error: Failed to read project status.\n");
        free(new_project);
        return;
    }
    if (!generate_id(new_project->id)) { 
        fprintf(stderr, "Error: Failed to generate project ID.\n");
        free(new_project);
        return;
    }
    new_project->next = list->head;
    list->head = new_project;
    printf("Project added successfully!\n");
}