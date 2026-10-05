void saveFile(FileManager *fm) {
    if (fm->file != NULL) {
        fflush(fm->file);
    }
}