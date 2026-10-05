void list_projects(ProjectList *list) {
    if (list->head == NULL) {
        printf("No projects available.\n");
        return;
    }
    Project *current = list->head;
    while (current != NULL) {
        printf("ID: %s\n", current->id);
        printf("Name: %s", current->name);
        printf("Description: %s", current->description);
        printf("Status: %s\n", current->status);
        current = current->next;
    }
}