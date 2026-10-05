char* findKeySignature(const char* notes) {
    char *keySignature = (char*)malloc(50 * sizeof(char));
    int noteCount[7] = {0}; 
    const char *noteNames = "CDEFGAB";
    for (int i = 0; i < strlen(notes); i++) {
        char *notePos = strchr(noteNames, notes[i]);
        if (notePos != NULL) {
            noteCount[notePos - noteNames]++;
        }
    }
    if (noteCount[0] > 0 && noteCount[4] > 0) {
        strcpy(keySignature, "C Major / A Minor");
    } else if (noteCount[4] > 0 && noteCount[1] > 0) {
        strcpy(keySignature, "G Major / E Minor");
    } else {
        strcpy(keySignature, "Unknown Key Signature");
    }
    return keySignature;
}