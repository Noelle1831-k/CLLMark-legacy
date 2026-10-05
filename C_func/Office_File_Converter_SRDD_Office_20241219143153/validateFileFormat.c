int validateFileFormat(const char *inputFile, const char *outputFormat) {
    printf("Validating file format for: %s to %s\n", inputFile, outputFormat);
    const char *inputExt = strrchr(inputFile, '.');
    if (inputExt) {
        inputExt++;
        if (strcmp(inputExt, "docx") == 0 || strcmp(inputExt, "xlsx") == 0 || strcmp(inputExt, "pptx") == 0 || strcmp(inputExt, "jpg") == 0 || strcmp(inputExt, "png") == 0) {
            return 1; 
        }
    }
    return 0; 
}