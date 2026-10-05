void addCorridor(int startX, int startY, int endX, int endY) {
    if (dungeonMap.corridorCount < MAX_CORRIDORS) {
        Corridor newCorridor = {startX, startY, endX, endY};
        dungeonMap.corridors[dungeonMap.corridorCount++] = newCorridor;
        printf("Corridor added from (%d, %d) to (%d, %d).\n", startX, startY, endX, endY);
    } else {
        logError("Maximum corridor limit reached.");
    }
}