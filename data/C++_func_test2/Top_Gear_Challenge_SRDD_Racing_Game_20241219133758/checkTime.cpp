bool Timer::checkTime() {
    if (timeRemaining > 0) {
        --timeRemaining;
        return true;
    }
    cout << "Time's up!\n";
    return false;
}