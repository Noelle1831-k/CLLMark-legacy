string getCurrentTime() {
    time_t now = time(0);
    tm* localtm = localtime(&now);
    return timeToString(*localtm);
}