void UserInterface::start() {
    int choice, workspaceId;
    std::string requirements;
    while (true) {
        std::cout << "1. View Floor Plan\n2. Book Workspace\n3. Exit\nEnter choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                floorPlan.displayFloorPlan();
                break;
            case 2:
                std::cout << "Enter Workspace ID to book: ";
                std::cin >> workspaceId;
                std::cout << "Enter special requirements: ";
                std::cin.ignore();
                std::getline(std::cin, requirements);
                if (bookingManager.makeBooking(workspaceId, requirements)) {
                    std::cout << "Booking successful!\n";
                } else {
                    std::cout << "Booking failed. Workspace may be unavailable.\n";
                }
                break;
            case 3:
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}