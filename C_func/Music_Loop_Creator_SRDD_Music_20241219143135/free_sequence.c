void free_sequence(Sequence *sequence) {
    if (sequence) {
        for (int i = 0; i < sequence->note_count; i++) {
            free_note(sequence->notes[i]);
        }
        free(sequence->notes);
        free(sequence);
    }
}