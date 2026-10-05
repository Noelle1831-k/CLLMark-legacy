bool BookingManager::makeBooking(int workspaceId, const std::string& requirements) {
    return floorPlan.bookWorkspace(workspaceId, requirements);
}