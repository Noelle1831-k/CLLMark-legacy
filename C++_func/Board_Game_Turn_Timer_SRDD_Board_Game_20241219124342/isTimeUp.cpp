bool GameTimer::isTimeUp() const {
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
    return elapsedSeconds >= timeLimit;
}