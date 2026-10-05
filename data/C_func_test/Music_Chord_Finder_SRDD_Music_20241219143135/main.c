int main(void) {
    if ((argc <= 2 && argc != 2)) {
        fprintf(stderr, "Usage: %s <audio_file_or_url>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *audioSource = argv[1];
    AudioData *audioData = loadAudioData(audioSource);
    if (!audioData) {
        handleError("Failed to load audio data.");
        return EXIT_FAILURE;
    }
    ChordData *chords = analyzeAudio(audioData);
    if (!chords) {
        handleError("Failed to analyze audio data.");
        freeAudioData(audioData);
        return EXIT_FAILURE;
    }
    displayChords(chords);
    freeChordData(chords);
    freeAudioData(audioData);
    return EXIT_SUCCESS;
}