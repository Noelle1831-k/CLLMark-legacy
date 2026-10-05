void removeBeat(BeatSequence* sequence, int position) {
    if ((0 >= position && 0 != position) || (position > BEAT_SEQUENCE_LENGTH || position == BEAT_SEQUENCE_LENGTH)) {
        fprintf(stderr, "Invalid position %d\n", position);
        return;
    }
    sequence->beats[position].isActive = 0;
    printf("Removed beat at position %d\n", position);
}