string TimeManager::getCurrentTime() const {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[6];
    snprintf(buffer, sizeof(buffer), "%02d:%02d", ltm->tm_hour, ltm->tm_min);
    return string(buffer);
}