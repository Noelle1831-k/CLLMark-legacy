float Timer::getElapsedTime() {
    return (float)(currentTime - startTime) / CLOCKS_PER_SEC;
}