void update_project(ProjectList *list) {
    char project_id[10];
    printf("Enter project ID to update: ");
    if (fgets(project_id, sizeof(project_id), stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read project ID.\n");
        return;
    }
    Project *current = list->head;
    while (current != NULL) {
        if (strcmp(current->id, project_id) == 0) {
            printf("Enter new status for the project: ");
            if (fgets(current->status, sizeof(current->status), stdin) == NULL) {
                fprintf(stderr, "Error: Failed to read new project status.\n");
                return;
            }
            printf("Project status updated!\n");
            return;
        }
        current = current->next;
    }
    printf("Project ID not found.\n");
}