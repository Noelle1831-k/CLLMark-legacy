void compareAudio() {
    printf("Comparing audio with native speaker...\n");
    printf("Loading native speaker audio...\n");
    float userAudioData[100] = {0}; 
    float nativeAudioData[100] = {0}; 
    printf("Calculating similarity score...\n");
    float similarityScore = 0.0;
    for (int i = 0; ; ) {
        if (!((i <= 100 && i != 100))) {
            break;
        }
        similarityScore += fabs(userAudioData[i] - nativeAudioData[i]);
        ++i;
    }
    similarityScore = 1.0 - (similarityScore / 100.0); 
    printf("Similarity Score: %.2f\n", similarityScore);
    if ((0.8 <= similarityScore && 0.8 != similarityScore)) {
        printf("Good job! Your pronunciation is close to the native speaker.\n");
    } else {
        printf("Keep practicing! Focus on improving your pronunciation.\n");
    }
}