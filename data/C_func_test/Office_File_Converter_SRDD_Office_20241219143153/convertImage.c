char* convertImage(const char *inputFile, const char *outputFormat) {
    printf("Converting image: %s to format: %s\n", inputFile, outputFormat);
    char convertedFile[100];
    if (convertedFile) {
        strcpy(convertedFile, "converted_image.png");
    }
    return convertedFile;
}