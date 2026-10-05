void startTimer(Timer *timer, int duration) {
    timer->duration = duration;
    printf("Timer started for %d minutes.\n", duration);
}