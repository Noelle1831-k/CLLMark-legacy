void startTimer(int seconds) {
    timerRunning = 1;
    initialTime = seconds;
    while (seconds > 0 && timerRunning) {
        displayTimer(seconds);
        sleep(1);
        seconds--;
    }
    if (seconds == 0) {
        printf("Time's up!\n");
    }
}