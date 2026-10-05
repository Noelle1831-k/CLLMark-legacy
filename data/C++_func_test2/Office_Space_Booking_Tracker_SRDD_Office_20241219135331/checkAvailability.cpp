bool FloorPlan::checkAvailability(int workspaceId) const {
    for (size_t i = 0; i < workspaces.size(); i++) {
        if (workspaces[i].getId() == workspaceId) {
            return workspaces[i].isAvailable();
        }
    }
    return false;
}