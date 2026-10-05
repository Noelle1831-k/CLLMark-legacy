void addBeat(BeatSequence* sequence, int soundId, int position) {
    if (position < 0 || position >= BEAT_SEQUENCE_LENGTH) {
        fprintf(stderr, "Invalid position %d\n", position);
        return;
    }
    sequence->beats[position].soundId = soundId;
    sequence->beats[position].isActive = 1;
    printf("Added beat with sound ID %d at position %d\n", soundId, position);
}