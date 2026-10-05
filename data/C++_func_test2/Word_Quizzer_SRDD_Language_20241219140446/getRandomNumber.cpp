int getRandomNumber(int min, int max) {
    return min + rand() % ((max + 1) - min);
}