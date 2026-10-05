char* timestamp() {
    time_t now = time(NULL);
    return ctime(&now);
}