void update_workspace(Workspace* workspaces, int num_workspaces, int id, const char* special_requirements) {
    for (int i = 0; i < num_workspaces; i++) {
        if (workspaces[i].id == id) {
            strcpy(workspaces[i].special_requirements, special_requirements);
            printf("Updated special requirements for workspace ID %d\n", id);
            return;
        }
    }
    printf("Workspace with ID %d not found.\n", id);
}