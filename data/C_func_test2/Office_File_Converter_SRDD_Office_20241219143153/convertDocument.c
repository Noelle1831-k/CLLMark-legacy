char* convertDocument(const char *inputFile, const char *outputFormat) {
    printf("Converting document: %s to format: %s\n", inputFile, outputFormat);
    char convertedFile[100];
    if (convertedFile) {
        strcpy(convertedFile, "converted_document.pdf");
    }
    return convertedFile;
}