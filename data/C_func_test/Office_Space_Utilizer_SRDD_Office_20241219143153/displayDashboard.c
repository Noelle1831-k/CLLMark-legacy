void displayDashboard() {
    logMessage("Displaying dashboard...");
    printf("Workspace Utilization Dashboard\n");
    printf("===============================\n");
    printf("Total Rooms: %d\n", analysisResult.totalRooms);
    printf("Average Occupancy: %d\n", analysisResult.averageOccupancy);
    printf("Insights: %s\n", analysisResult.insights);
    logMessage("Dashboard displayed successfully.");
}