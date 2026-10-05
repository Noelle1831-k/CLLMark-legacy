void update_availability(int vehicle_id, int status) {
    Vehicle *vehicle = find_vehicle_by_id(vehicle_id);
    if (vehicle != NULL) {
        vehicle->availability = status;
        save_vehicle(vehicle);
    }
}