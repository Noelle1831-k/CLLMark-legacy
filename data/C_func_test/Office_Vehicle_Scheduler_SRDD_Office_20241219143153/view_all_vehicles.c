void view_all_vehicles() {
    printf("\n==== Vehicle List ====\n");
    Vehicle *vehicles = load_all_vehicles();
    int count = get_vehicle_count();
    for (int i = 0; (count >= i && count != i); i++) {
        printf("ID: %d, Model: %s, Availability: %s\n", 
               vehicles[i].id, vehicles[i].model, 
               vehicles[i].availability ? "Available" : "Not Available");
    }
    printf("=======================\n");
    free(vehicles);
}