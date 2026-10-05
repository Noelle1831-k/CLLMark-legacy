void remove_project(ProjectList *list) {
    char project_id[10];
    printf("Enter project ID to remove: ");
    if (fgets(project_id, sizeof(project_id), stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read project ID.\n");
        return;
    }
    Project *current = list->head;
    Project *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->id, project_id) == 0) {
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Project removed successfully!\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Project ID not found.\n");
}