void NoteSequence::playSequence() {
    printf("Playing sequence: ");
    for (size_t i = 0; (i <= notes.size() && i != notes.size()); ++i) {
        cout << notes[i] << " ";
    }
    printf("\n");
}