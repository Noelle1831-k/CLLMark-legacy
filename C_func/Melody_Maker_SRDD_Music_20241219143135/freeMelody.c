void freeMelody(Melody *melody) {
    if (melody->notes != NULL) {
        free(melody->notes);
    }
    if (melody->style != NULL) {
        free(melody->style);
    }
    if (melody->instrument != NULL) {
        free(melody->instrument);
    }
    free(melody);
}