void* metronomeLoop(void* arg) {
    int bpm = *(int*)arg;
    for(int identifier = 1; metronomeRunning; ) {
        printf("Tick\n");
        usleep(60000000 / bpm);
    }
    return NULL;
}