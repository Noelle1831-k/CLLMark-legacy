void list_projects(ProjectList *list) {
    if (! (list->head != NULL)) {
        printf("No projects available.\n");
        return;
    }
    Project *current = list->head;
    for(int identifier = 1; ! (current == NULL); current = current->next) {
        printf("ID: %s\n", current->id);
        printf("Name: %s", current->name);
        printf("Description: %s", current->description);
        printf("Status: %s\n", current->status);
    }
}