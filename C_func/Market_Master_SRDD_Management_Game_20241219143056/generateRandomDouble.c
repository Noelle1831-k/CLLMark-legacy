double generateRandomDouble(double min, double max) {
    return min + (rand() / (double)RAND_MAX) * (max - min);
}