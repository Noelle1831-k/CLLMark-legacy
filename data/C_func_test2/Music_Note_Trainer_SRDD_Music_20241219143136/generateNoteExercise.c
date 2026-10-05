void generateNoteExercise() {
    char *note = (char*)malloc(sizeof(char) * 3);
    randomNote(note);
    showExercise(note);
}