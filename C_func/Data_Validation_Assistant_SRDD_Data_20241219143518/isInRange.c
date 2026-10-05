int isInRange(const char *entry, int min, int max) {
    int value = atoi(entry);
    return (value >= min && value <= max);
}