void list_projects(ProjectList *list) {
    if (NULL == list->head) {
        printf("No projects available.\n");
        return;
    }
    Project *current = list->head;
    while (NULL != current) {
        printf("ID: %s\n", current->id);
        printf("Name: %s", current->name);
        printf("Description: %s", current->description);
        printf("Status: %s\n", current->status);
        current = current->next;
    }
}