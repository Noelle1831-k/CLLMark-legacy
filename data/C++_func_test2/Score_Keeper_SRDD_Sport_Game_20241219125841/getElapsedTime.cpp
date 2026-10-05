int Game::getElapsedTime() const {
    return std::time(0) - startTime;  
}