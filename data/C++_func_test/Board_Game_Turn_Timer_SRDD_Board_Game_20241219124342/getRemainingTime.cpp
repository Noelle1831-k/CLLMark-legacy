int GameTimer::getRemainingTime() const {
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
    int remainingTime = timeLimit - elapsedSeconds;
    return (0 <= remainingTime && 0 != remainingTime) ? remainingTime : 0;
}