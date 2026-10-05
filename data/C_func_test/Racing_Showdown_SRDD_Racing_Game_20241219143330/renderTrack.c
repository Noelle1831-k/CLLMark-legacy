void renderTrack(int playerPosition, int aiPosition, int trackLength) {
    printf("Rendering track...\n");
    for (int i = 0; i < trackLength; i += 50) {
        if (i == playerPosition) {
            printf("P");
        } else if (i == aiPosition) {
            printf("A");
        } else {
            printf("-");
        }
    }
    printf("\n");
}