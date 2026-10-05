void getScaleNotes(char *root, char *scaleType, char scaleNotes[]) {
    int intervals[7];
    int numNotes = 0;
    if (strcmp(scaleType, "major") == 0) {
        int majorIntervals[] = {2, 4, 5, 7, 9, 11, 12};
        memcpy(intervals, majorIntervals, sizeof(majorIntervals));
        numNotes = 7;
    } else if (strcmp(scaleType, "minor") == 0) {
        int minorIntervals[] = {2, 3, 5, 7, 8, 10, 12};
        memcpy(intervals, minorIntervals, sizeof(minorIntervals));
        numNotes = 7;
    } else if (strcmp(scaleType, "pentatonic") == 0) {
        int pentatonicIntervals[] = {2, 4, 5, 7, 9};
        memcpy(intervals, pentatonicIntervals, sizeof(pentatonicIntervals));
        numNotes = 5;
    }
    for (int i = 0; i < numNotes; i++) {
        char *note = getNoteAtInterval(root, intervals[i]);
        scaleNotes[i] = *note;
    }
    scaleNotes[numNotes] = '\0';
}