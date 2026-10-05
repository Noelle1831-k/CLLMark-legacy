void FleetManager::listAvailableVehicles() {
    cout << "Available Vehicles:\n";
    for (vector<Vehicle>::iterator it = fleet.begin(); it != fleet.end(); ++it) {
        if (it->checkAvailability()) {
            cout << "Vehicle ID: " << it->getId() << "\n";
        }
    }
}