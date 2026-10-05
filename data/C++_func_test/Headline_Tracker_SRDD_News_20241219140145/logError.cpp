void logError(string errorMessage) {
    time_t now = time(0);
    char* dt = ctime(&now);
    cerr << "[" << dt << "] " << errorMessage << endl;
}