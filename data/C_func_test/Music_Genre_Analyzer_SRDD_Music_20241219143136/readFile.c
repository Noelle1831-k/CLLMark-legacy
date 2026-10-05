int readFile(const char *filePath, char **buffer) {
    FILE *file = fopen(filePath, "rb");
    if (!file) return 0;
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);
    *buffer = (char *)malloc(fileSize + 1);
    if (!*buffer) {
        fclose(file);
        return 0;
    }
    fread(*buffer, 1, fileSize, file);
    (*buffer)[fileSize] = '\0';
    fclose(file);
    return 1;
}