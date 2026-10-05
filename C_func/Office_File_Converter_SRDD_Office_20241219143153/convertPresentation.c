char* convertPresentation(const char *inputFile, const char *outputFormat) {
    printf("Converting presentation: %s to format: %s\n", inputFile, outputFormat);
    char *convertedFile = (char *)malloc(100);
    if (convertedFile) {
        strcpy(convertedFile, "converted_presentation.pdf");
    }
    return convertedFile;
}