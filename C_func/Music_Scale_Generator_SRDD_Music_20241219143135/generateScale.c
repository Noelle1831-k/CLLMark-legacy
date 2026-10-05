void generateScale(char *root, char *scaleType, char scaleNotes[]) {
    if (strcmp(scaleType, "major") == 0) {
        getScaleNotes(root, "major", scaleNotes);
    } else if (strcmp(scaleType, "minor") == 0) {
        getScaleNotes(root, "minor", scaleNotes);
    } else if (strcmp(scaleType, "pentatonic") == 0) {
        getScaleNotes(root, "pentatonic", scaleNotes);
    } else {
        printf("Unknown scale type\n");
    }
}