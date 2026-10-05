int generateRequestId() {
    static int id = 1;
    return id++;
}