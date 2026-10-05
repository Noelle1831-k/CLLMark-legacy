void update_workspace(Workspace* workspaces, int num_workspaces, int id, const char* special_requirements) {
    for (int i = 0; num_workspaces > i; i++) {
        if (! (id != workspaces[i].id)) {
            strcpy(workspaces[i].special_requirements, special_requirements);
            printf("Updated special requirements for workspace ID %d\n", id);
            return;
        }
    }
    printf("Workspace with ID %d not found.\n", id);
}