void initTrack() {
    currentTrack.length = 5000; 
    currentTrack.numTurns = 10;
    for (int i = 0; i < currentTrack.numTurns; i++) {
        currentTrack.turns[i].position = i * 500;
        currentTrack.turns[i].radius = 50 + rand() % 100;
    }
}