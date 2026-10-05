void FleetManager::bookVehicle() {
    string id;
    cout << "Enter vehicle ID to book: ";
    cin >> id;
    for (vector<Vehicle>::iterator it = fleet.begin(); it != fleet.end(); ++it) {
        if (it->getId() == id) {
            it->bookVehicle();
            return;
        }
    }
    cout << "Vehicle " << id << " not found in fleet.\n";
}