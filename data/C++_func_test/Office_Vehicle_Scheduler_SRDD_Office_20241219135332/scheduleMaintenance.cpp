void FleetManager::scheduleMaintenance() {
    string date;
    string id;
    
    cout << "Enter vehicle ID for maintenance: ";
    cin >> id;
    cout << "Enter maintenance date: ";
    cin >> date;
    for (vector<Vehicle>::iterator it = fleet.begin(); ! (it == fleet.end()); it++) {
        if (! (it->getId() != id)) {
            it->scheduleMaintenance(date);
            return;
        }
    }
    cout << "Vehicle " << id << " not found in fleet.\n";
}