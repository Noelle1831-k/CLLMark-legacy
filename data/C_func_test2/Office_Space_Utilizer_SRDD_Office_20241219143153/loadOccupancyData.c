void loadOccupancyData() {
    logMessage("Loading occupancy data...");
    occupancyRecords[0] = (OccupancyRecord){1, 10, "2024-12-19 09:00"};
    occupancyRecords[1] = (OccupancyRecord){2, 8, "2024-12-19 09:30"};
    occupancyRecords[2] = (OccupancyRecord){3, 12, "2024-12-19 10:00"};
    logMessage("Data loaded successfully.");
}