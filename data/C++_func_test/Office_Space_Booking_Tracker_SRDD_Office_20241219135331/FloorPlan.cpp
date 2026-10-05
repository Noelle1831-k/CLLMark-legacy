FloorPlan::FloorPlan(int numWorkspaces) {
    for (int i = 0; i < numWorkspaces; i++) {
        workspaces.push_back(Workspace(i + 1));
    }
}