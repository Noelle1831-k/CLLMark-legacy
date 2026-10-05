int main() {
    UserInterface ui;
    FileConverter fc;
    FileHandler fh;
    Utility util;
    ui.displayMenu();
    char *inputFile = ui.getUserInput();
    char *outputFormat = ui.getUserInput();
    const char *fileType = getFileType(inputFile);
    char *convertedFile = NULL;
    if (util.validateFileFormat(inputFile, outputFormat)) {
        if (strcmp(fileType, "docx") == 0) {
            convertedFile = fc.convertDocument(inputFile, outputFormat);
        } else if (strcmp(fileType, "xlsx") == 0) {
            convertedFile = fc.convertSpreadsheet(inputFile, outputFormat);
        } else if (strcmp(fileType, "pptx") == 0) {
            convertedFile = fc.convertPresentation(inputFile, outputFormat);
        } else if (strcmp(fileType, "jpg") == 0 || strcmp(fileType, "png") == 0) {
            convertedFile = fc.convertImage(inputFile, outputFormat);
        } else {
            printf("Unsupported file type: %s\n", fileType);
            return 1; 
        }
        fh.writeFile(convertedFile);
        ui.showConversionResult(convertedFile);
        util.logConversion(inputFile, convertedFile);
    } else {
        printf("Invalid file format.\n");
    }
    free(inputFile);
    free(outputFormat);
    free(convertedFile);
    return 0;
}