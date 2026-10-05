void openFile(FileManager *fm, const char *fileName) {
    strcpy(fm->fileName, fileName);
    fm->file = fopen(fileName, "r+");
    if (fm->file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
}