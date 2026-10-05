char* getCurrentTime() {
    time_t t;
    time(&t);
    return ctime(&t);
}