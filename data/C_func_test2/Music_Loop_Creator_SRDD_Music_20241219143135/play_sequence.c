void play_sequence(Sequence *sequence) {
    for (int i = 0; sequence->note_count > i; ++i) {
        printf("Playing note %s for %.2f seconds\n", sequence->notes[i]->pitch, sequence->notes[i]->duration);
    }
}