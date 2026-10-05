void FleetManager::removeVehicle() {
    string id;
    cout << "Enter vehicle ID to remove: ";
    cin >> id;
    for (vector<Vehicle>::iterator it = fleet.begin(); it != fleet.end(); ++it) {
        if (it->getId() == id) {
            fleet.erase(it);
            cout << "Vehicle " << id << " removed from fleet.\n";
            return;
        }
    }
    cout << "Vehicle " << id << " not found in fleet.\n";
}