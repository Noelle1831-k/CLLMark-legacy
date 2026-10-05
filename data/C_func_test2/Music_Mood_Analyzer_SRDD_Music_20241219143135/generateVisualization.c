int generateVisualization(MoodDescriptor mood, AudioFeatures features) {
    printf("Visualizing mood: %s\n", moodToString(mood));
    printf("Tempo: %d BPM, Key: %d, Instrumentation: %d, Harmonic Structure: %d\n", 
            features.tempo, features.key, features.instrumentation, features.harmonicStructure);
    switch (mood) {
        case HAPPY:
            printf("Happy Mood: [**********]\n");
            break;
        case SAD:
            printf("Sad Mood: [******    ]\n");
            break;
        case ENERGETIC:
            printf("Energetic Mood: [**************]\n");
            break;
        case CALM:
            printf("Calm Mood: [****        ]\n");
            break;
        default:
            printf("Unknown Mood: [???????]\n");
            break;
    }
    return 1;
}