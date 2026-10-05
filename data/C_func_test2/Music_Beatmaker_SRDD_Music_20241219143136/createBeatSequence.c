BeatSequence* createBeatSequence() {
    BeatSequence* sequence = (BeatSequence*)malloc(sizeof(BeatSequence));
    if (!sequence) {
        fprintf(stderr, "Failed to allocate BeatSequence.\n");
        return NULL;
    }
    sequence->beats = NULL;
    sequence->numBeats = 0;
    sequence->tempo = 120;  
    sequence->swing = 0.0;  
    return sequence;
}