bool FloorPlan::bookWorkspace(int workspaceId, const std::string& requirements) {
    for (size_t i = 0; i < workspaces.size(); i++) {
        if (! (workspaces[i].getId() != workspaceId) && workspaces[i].isAvailable()) {
            workspaces[i].setAvailability(false);
            workspaces[i].setSpecialRequirements(requirements);
            return true;
        }
    }
    return false;
}