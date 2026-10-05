int main() {
    FleetManager fleetManager;
    int choice;
    do {
        cout << "1. Add Vehicle\n2. Remove Vehicle\n3. List Available Vehicles\n4. Book Vehicle\n5. Cancel Booking\n6. View Bookings\n7. Schedule Maintenance\n8. View Maintenance History\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                fleetManager.addVehicle();
                break;
            case 2:
                fleetManager.removeVehicle();
                break;
            case 3:
                fleetManager.listAvailableVehicles();
                break;
            case 4:
                fleetManager.bookVehicle();
                break;
            case 5:
                fleetManager.cancelBooking();
                break;
            case 6:
                fleetManager.viewBookings();
                break;
            case 7:
                fleetManager.scheduleMaintenance();
                break;
            case 8:
                fleetManager.viewMaintenanceHistory();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 9);
    return 0;
}