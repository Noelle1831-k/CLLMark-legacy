void FleetManager::addVehicle() {
    string id;
    cout << "Enter vehicle ID to add: ";
    cin >> id;
    Vehicle newVehicle(id);
    fleet.push_back(newVehicle);
    cout << "Vehicle " << id << " added to fleet.\n";
}