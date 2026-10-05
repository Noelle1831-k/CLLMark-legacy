void cleanupGame() {
    printf("Cleaning up resources...\n");
    freeCars();
    freeTracks();
    closeGraphics();
}