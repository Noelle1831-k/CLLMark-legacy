void startMetronome(int bpm) {
    if (metronomeRunning) {
        printf("Metronome is already running.\n");
        return;
    }
    metronomeRunning = 1;
    pthread_create(&metronomeThread, NULL, metronomeLoop, &bpm);
    printf("Metronome started at %d BPM.\n", bpm);
}