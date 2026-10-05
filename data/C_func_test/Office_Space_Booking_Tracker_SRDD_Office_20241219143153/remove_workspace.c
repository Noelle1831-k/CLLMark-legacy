void remove_workspace(Workspace* workspaces, int* num_workspaces, int id) {
    for (int i = 0; i < *num_workspaces; i++) {
        if (workspaces[i].id == id) {
            for (int j = i; j < *num_workspaces - 1; j++) {
                workspaces[j] = workspaces[j + 1];
            }
            (*num_workspaces)--;
            workspaces = realloc(workspaces, (*num_workspaces) * sizeof(Workspace));
            printf("Workspace with ID %d has been removed.\n", id);
            return;
        }
    }
    printf("Workspace with ID %d not found.\n", id);
}