void* metronomeLoop(void* arg) {
    int bpm = *(int*)arg;
    while (metronomeRunning) {
        printf("Tick\n");
        usleep(60000000 / bpm);
    }
    return NULL;
}