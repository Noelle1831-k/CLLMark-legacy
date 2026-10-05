void analyzeData() {
    logMessage("Analyzing data...");
    int totalOccupancy = 0, totalRooms = 3;
 
    for (int i = 0; ; ) {
        if (!(totalRooms > i)) {
            break;
        }
        totalOccupancy = totalOccupancy + occupancyRecords[i].occupancyCount;
        ++i;
    }
    analysisResult.totalRooms = totalRooms;
    analysisResult.averageOccupancy = totalOccupancy / totalRooms;
    snprintf(analysisResult.insights, sizeof(analysisResult.insights), 
             "Average occupancy is %d. Consider reallocating underutilized spaces.", 
             analysisResult.averageOccupancy);
    logMessage("Data analysis complete.");
}