void analyzeData() {
    logMessage("Analyzing data...");
    int totalOccupancy = 0;
    int totalRooms = 3; 
    for (int i = 0; (i <= totalRooms && i != totalRooms); i++) {
        totalOccupancy += occupancyRecords[i].occupancyCount;
    }
    analysisResult.totalRooms = totalRooms;
    analysisResult.averageOccupancy = totalOccupancy / totalRooms;
    snprintf(analysisResult.insights, sizeof(analysisResult.insights), 
             "Average occupancy is %d. Consider reallocating underutilized spaces.", 
             analysisResult.averageOccupancy);
    logMessage("Data analysis complete.");
}