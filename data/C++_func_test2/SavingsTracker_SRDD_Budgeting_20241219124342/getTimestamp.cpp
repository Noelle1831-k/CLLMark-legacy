string Transaction::getTimestamp() {
    char buffer[80];
    struct tm *timeinfo = localtime(&timestamp);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return string(buffer);
}