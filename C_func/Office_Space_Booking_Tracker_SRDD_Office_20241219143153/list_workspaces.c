void list_workspaces(const Workspace* workspaces, int num_workspaces) {
    for (int i = 0; i < num_workspaces; i++) {
        if (workspaces[i].is_available) {
            printf("ID: %d, Name: %s, Location: %s, Floor: %d\n", 
                workspaces[i].id, workspaces[i].name, workspaces[i].location, workspaces[i].floor_number);
        }
    }
}