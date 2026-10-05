int Utilities::random(int min, int max) {
    return min + rand() % (max - min + 1);
}