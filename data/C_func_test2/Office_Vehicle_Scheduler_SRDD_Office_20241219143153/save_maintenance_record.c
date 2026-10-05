void save_maintenance_record(int vehicle_id, const char *details) {
    MaintenanceRecord record;
    record.vehicle_id = vehicle_id;
    get_current_date(record.maintenance_date, 20);
    strncpy(record.details, details, 256);
    save_maintenance(&record);
}