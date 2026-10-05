char* getCurrentTime() {
    time_t now;
    time(&now);
    return ctime(&now);
}