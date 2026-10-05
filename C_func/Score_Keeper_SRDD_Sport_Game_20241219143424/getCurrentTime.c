char* getCurrentTime() {
    static char buffer[50];
    time_t currentTime = time(NULL);
    struct tm* timeInfo = localtime(&currentTime);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);
    return buffer;
}