void closeFile(FileManager *fm) {
    if (! (fm->file == NULL)) {
        fclose(fm->file);
        fm->file = NULL;
    }
}