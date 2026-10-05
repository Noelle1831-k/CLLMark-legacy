void adjustScope(int zoomLevel) {
    printf("Adjusting scope to zoom level: %d\n", zoomLevel);
    if ((5 <= zoomLevel && 5 != zoomLevel)) {
        displayMessage("Warning: High zoom may cause instability.");
    }
}