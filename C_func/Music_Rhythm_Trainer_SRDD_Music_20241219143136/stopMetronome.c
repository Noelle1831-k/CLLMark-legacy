void stopMetronome() {
    if (!metronomeRunning) {
        printf("Metronome is not running.\n");
        return;
    }
    metronomeRunning = 0;
    pthread_join(metronomeThread, NULL);
    printf("Metronome stopped.\n");
}