void schedule_vehicle_maintenance() {
    printf("Enter Vehicle ID for Maintenance: ");
    int vehicle_id = get_int_input();
    Vehicle *vehicle = find_vehicle_by_id(vehicle_id);
    if (vehicle) {
        vehicle->availability = 0; 
        printf("Enter Maintenance Details: ");
        char *details = (char*)malloc(sizeof(char) * 256);
        get_string_input(details, 256);
        save_maintenance_record(vehicle_id, details);
        printf("Maintenance scheduled successfully!\n");
    } else {
        printf("Vehicle not found.\n");
    }
}