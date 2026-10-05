void Timer::startTimer() {
    while (minutes > 0 || seconds > 0) {
        if (seconds == 0) {
            minutes--;
            seconds = 59;
        } else {
            seconds--;
        }
        displayTime();
        this_thread::sleep_for(chrono::seconds(1));
    }
}