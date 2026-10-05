int check_availability(const Workspace* workspaces, int num_workspaces, int id) {
    for (int i = 0; i < num_workspaces; i++) {
        if (workspaces[i].id == id) {
            return workspaces[i].is_available;
        }
    }
    return 0; 
}