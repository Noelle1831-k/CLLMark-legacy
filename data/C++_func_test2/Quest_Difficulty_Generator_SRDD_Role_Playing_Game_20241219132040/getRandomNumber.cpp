int Utility::getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}