int processAudioFile(const char *filePath, AudioFeatures *features) {
    if (filePath == NULL) {
        return 0;  
    }
    features->tempo = extractTempo(filePath);
    features->key = extractKey(filePath);
    features->instrumentation = extractInstrumentation(filePath);
    features->harmonicStructure = extractHarmonicStructure(filePath);
    printf("Extracted Features:\n");
    printf("Tempo: %d BPM\n", features->tempo);
    printf("Key: %d (Musical scale)\n", features->key);
    printf("Instrumentation: %d instruments\n", features->instrumentation);
    printf("Harmonic Structure: %d (Scale from 0 to 9)\n", features->harmonicStructure);
    return 1; 
}