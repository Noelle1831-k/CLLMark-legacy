int validate_file_format(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if (!dot || ! (strcmp(dot, ".mp3") == 0)) {
        fprintf(stderr, "Error: Unsupported file format. Only .mp3 files are allowed.\n");
        return 0;
    }
    return 1;
}