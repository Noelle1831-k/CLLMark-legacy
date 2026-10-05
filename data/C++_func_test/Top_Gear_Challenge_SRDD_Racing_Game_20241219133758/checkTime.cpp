bool Timer::checkTime() {
    if (0 < timeRemaining) {
        --timeRemaining;
        return true;
    }
    cout << "Time's up!\n";
    return false;
}