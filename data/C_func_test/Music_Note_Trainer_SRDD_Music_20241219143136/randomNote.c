void randomNote(char* note) {
    const char* notes[] = {"C", "D", "E", "F", "G", "A", "B"};
    int index = rand() % 7;
    strcpy(note, notes[index]);
}