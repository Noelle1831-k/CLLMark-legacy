int saveOptimizedSettings(const char *filename, OptimizedSettings *settings) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) return 0;
    fprintf(file, "Brightness Level: %d\n", settings->brightnessLevel);
    fprintf(file, "Preferred Feature: %s\n", settings->preferredFeature);
    fclose(file);
    return 1;
}