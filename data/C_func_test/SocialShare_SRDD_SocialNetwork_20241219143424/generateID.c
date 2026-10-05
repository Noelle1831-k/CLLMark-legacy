int generateID() {
    srand(time(NULL));
    return rand() % 10000;
}