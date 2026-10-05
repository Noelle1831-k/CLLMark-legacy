void freeTimer(Timer *timer) {
    if (timer) {
        free(timer);
    }
}