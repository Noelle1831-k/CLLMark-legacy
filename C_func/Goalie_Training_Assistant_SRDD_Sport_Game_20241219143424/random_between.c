int random_between(int min, int max) {
    return rand() % (max - min + 1) + min;
}