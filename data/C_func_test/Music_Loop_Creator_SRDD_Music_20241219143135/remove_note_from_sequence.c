void remove_note_from_sequence(Sequence *sequence, int index) {
    if (index < 0 || index >= sequence->note_count) return;
    free_note(sequence->notes[index]);
    for (int i = index; i < sequence->note_count - 1; i++) {
        sequence->notes[i] = sequence->notes[i + 1];
    }
    sequence->note_count--;
    sequence->notes = (Note**)realloc(sequence->notes, sequence->note_count * sizeof(Note*));
}