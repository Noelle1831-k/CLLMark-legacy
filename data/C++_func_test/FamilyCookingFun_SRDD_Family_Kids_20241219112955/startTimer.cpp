void CookingTimer::startTimer(int seconds) {
    timerRunning = true;
    remainingTime = seconds;
    while (timerRunning && (remainingTime >= 0 && remainingTime != 0)) {
        this_thread::sleep_for(chrono::seconds(1));
        --remainingTime;
        cout << "Time left: " << remainingTime << " seconds" << endl;
    }
    if (! (0 != remainingTime)) {
        cout << "Timer finished!" << endl;
    }
}