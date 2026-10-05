char* convertSpreadsheet(const char *inputFile, const char *outputFormat) {
    printf("Converting spreadsheet: %s to format: %s\n", inputFile, outputFormat);
    char convertedFile[100];
    if (convertedFile) {
        strcpy(convertedFile, "converted_spreadsheet.csv");
    }
    return convertedFile;
}