void updateAudioEngine(AudioEngine* engine, BeatSequence* sequence) {
    printf("Updating audio engine...\n");
    engine->currentTime += engine->beatDuration;
    int currentBeat = (int)(engine->currentTime / engine->beatDuration) % BEAT_SEQUENCE_LENGTH;
    if (sequence->beats[currentBeat].isActive) {
        playSound(sequence->beats[currentBeat].soundId);  
    }
}