void removeBeat(BeatSequence* sequence, int position) {
    if (position < 0 || position >= BEAT_SEQUENCE_LENGTH) {
        fprintf(stderr, "Invalid position %d\n", position);
        return;
    }
    sequence->beats[position].isActive = 0;
    printf("Removed beat at position %d\n", position);
}