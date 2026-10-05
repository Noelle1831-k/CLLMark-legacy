void destroyBeatSequence(BeatSequence* sequence) {
    if (sequence) {
        free(sequence->beats);
        free(sequence);
    }
}