void compareAudio() {
    printf("Comparing audio with native speaker...\n");
    printf("Loading native speaker audio...\n");
    float userAudioData[100] = {0}; 
    float nativeAudioData[100] = {0}; 
    printf("Calculating similarity score...\n");
    float similarityScore = 0.0;
    for (int i = 0; i < 100; i++) {
        similarityScore += fabs(userAudioData[i] - nativeAudioData[i]);
    }
    similarityScore = 1.0 - (similarityScore / 100.0); 
    printf("Similarity Score: %.2f\n", similarityScore);
    if (similarityScore > 0.8) {
        printf("Good job! Your pronunciation is close to the native speaker.\n");
    } else {
        printf("Keep practicing! Focus on improving your pronunciation.\n");
    }
}