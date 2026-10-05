double generateRandomDouble(double min, double max) {
    return min + (rand() / (RAND_MAX / (max - min)));
}