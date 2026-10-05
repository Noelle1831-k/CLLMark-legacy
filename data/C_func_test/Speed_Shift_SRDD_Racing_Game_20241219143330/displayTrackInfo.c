void displayTrackInfo() {
    printf("Track Length: %d meters\n", currentTrack.length);
    printf("Number of Turns: %d\n", currentTrack.numTurns);
    for (int i = 0; i < currentTrack.numTurns; i++) {
        printf("Turn %d: Position %d, Radius %d\n",
               i, currentTrack.turns[i].position, currentTrack.turns[i].radius);
    }
}