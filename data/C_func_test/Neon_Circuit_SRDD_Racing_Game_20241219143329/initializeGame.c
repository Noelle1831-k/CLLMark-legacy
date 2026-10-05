int initializeGame() {
    if (!initializeGraphics() || !initializeTrack() || !initializeVehicles() || !initializeAudio()) {
        return 0;
    }
    playBackgroundMusic();
    return 1;
}