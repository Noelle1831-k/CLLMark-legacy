void add_note_to_sequence(Sequence *sequence, Note *note) {
    sequence->note_count++;
    sequence->notes = (Note**)realloc(sequence->notes, sequence->note_count * sizeof(Note*));
    sequence->notes[sequence->note_count - 1] = note;
}