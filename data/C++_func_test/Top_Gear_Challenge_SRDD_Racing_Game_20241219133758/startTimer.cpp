void Timer::startTimer(int seconds) {
    timeLimit = seconds;
    timeRemaining = seconds;
    cout << "Timer started for " << timeLimit << " seconds.\n";
}