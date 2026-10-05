void FloorPlan::displayFloorPlan() const {
    for (size_t i = 0; i < workspaces.size(); i++) {
        std::cout << "Workspace " << workspaces[i].getId() << ": "
                  << (workspaces[i].isAvailable() ? "Available" : "Booked")
                  << " | Requirements: " << workspaces[i].getSpecialRequirements() << std::endl;
    }
}