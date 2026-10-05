void loadText(TextAnalyzer *analyzer, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    analyzer->text = (char*)malloc(length + 1);
    fread(analyzer->text, 1, length, file);
    analyzer->text[length] = '\0';
    fclose(file);
}