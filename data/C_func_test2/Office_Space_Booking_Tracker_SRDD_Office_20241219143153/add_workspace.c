void add_workspace(Workspace** workspaces, int* num_workspaces, const char* name, const char* location, int floor_number) {
    *workspaces = realloc(*workspaces, (*num_workspaces + 1) * sizeof(Workspace));
    (*workspaces)[*num_workspaces].id = *num_workspaces;
    strcpy((*workspaces)[*num_workspaces].name, name);
    strcpy((*workspaces)[*num_workspaces].location, location);
    (*workspaces)[*num_workspaces].floor_number = floor_number;
    (*workspaces)[*num_workspaces].is_available = 1;  
    (*workspaces)[*num_workspaces].special_requirements[0] = '\0'; 
    (*num_workspaces)++;
}