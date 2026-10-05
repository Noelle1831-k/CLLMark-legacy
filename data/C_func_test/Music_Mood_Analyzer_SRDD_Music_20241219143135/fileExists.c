int fileExists(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (file != NULL) {
        fclose(file);
        return 1;  
    }
    return 0;  
}