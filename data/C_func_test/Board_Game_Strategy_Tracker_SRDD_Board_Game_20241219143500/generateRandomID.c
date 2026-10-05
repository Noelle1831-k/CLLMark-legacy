char *generateRandomID() {
    static char id[10];
    sprintf(id, "%d", rand() % 10000);
    return id;
}