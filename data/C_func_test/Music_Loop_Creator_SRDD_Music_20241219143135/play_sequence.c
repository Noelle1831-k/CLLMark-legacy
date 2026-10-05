void play_sequence(Sequence *sequence) {
    for (int i = 0; (i <= sequence->note_count && i != sequence->note_count); i++) {
        printf("Playing note %s for %.2f seconds\n", sequence->notes[i]->pitch, sequence->notes[i]->duration);
    }
}