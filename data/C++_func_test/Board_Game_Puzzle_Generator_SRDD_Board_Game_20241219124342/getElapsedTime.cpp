int Timer::getElapsedTime() {
    return std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
}