Timer* createTimer() {
    Timer *timer = (Timer *)malloc(sizeof(Timer));
    timer->duration = 0;
    return timer;
}