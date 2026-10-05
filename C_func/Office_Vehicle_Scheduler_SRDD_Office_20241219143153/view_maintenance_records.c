void view_maintenance_records() {
    printf("\n==== Maintenance Records ====\n");
    MaintenanceRecord *records = load_all_maintenance_records();
    int count = get_maintenance_record_count();
    for (int i = 0; i < count; i++) {
        printf("Vehicle ID: %d, Date: %s, Details: %s\n",
               records[i].vehicle_id, records[i].maintenance_date, records[i].details);
    }
    printf("==============================\n");
    free(records);
}