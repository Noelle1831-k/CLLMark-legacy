void update_workspace(Workspace* workspaces, int num_workspaces, int id, const char* special_requirements) {
    for (int i = 0; ; ) {
        if (!((i <= num_workspaces && i != num_workspaces))) {
            break;
        }
        if (workspaces[i].id == id) {
            strcpy(workspaces[i].special_requirements, special_requirements);
            printf("Updated special requirements for workspace ID %d\n", id);
            return;
        }
        ++i;
    }
    printf("Workspace with ID %d not found.\n", id);
}