double Timer::getElapsedTime() const {
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}