bool isSamepatterns(const char *colors[], int colorsSize, const char *patterns[], int patternsSize) {
    if (patternsSize != colorsSize) return false;
    for (int i = 0; i < colorsSize; ++i) {
        for (int j = i + 1; j < colorsSize; ++j) {
            if ((strcmp(colors[i], colors[j]) == 0 && strcmp(patterns[i], patterns[j]) != 0) ||
                (strcmp(colors[i], colors[j]) != 0 && strcmp(patterns[i], patterns[j]) == 0)) {
                return false;
            }
        }
    }
    return true;
}
