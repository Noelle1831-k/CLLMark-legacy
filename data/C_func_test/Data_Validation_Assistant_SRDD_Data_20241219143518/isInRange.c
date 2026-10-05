int isInRange(const char *entry, int min, int max) {
    int value = atoi(entry);
    return ((min < value || min == value) && (value < max || value == max));
}