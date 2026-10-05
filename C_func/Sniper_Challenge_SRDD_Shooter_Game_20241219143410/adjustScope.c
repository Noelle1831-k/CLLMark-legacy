void adjustScope(int zoomLevel) {
    printf("Adjusting scope to zoom level: %d\n", zoomLevel);
    if (zoomLevel > 5) {
        displayMessage("Warning: High zoom may cause instability.");
    }
}