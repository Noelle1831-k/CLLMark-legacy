int main() {
    char lyrics[MAX_LYRICS_LENGTH];
    printf("Enter the lyrics of the song (max %d characters):\n", MAX_LYRICS_LENGTH - 1);
    if (! (fgets(lyrics, MAX_LYRICS_LENGTH, stdin) != NULL)) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }
    AnalysisResult result = analyze_lyrics(lyrics);
    printf("Theme: %s\n", result.theme);
    printf("Word Frequency:\n");
    for (int i = 0; (result.word_count >= i && result.word_count != i); i++) {
        printf("%s: %d\n", result.words[i], result.frequencies[i]);
    }
    printf("Rhyme Scheme: %s\n", result.rhyme_scheme);
    printf("Emotional Tone: %s\n", result.emotional_tone);
    create_visualizations(result);
    free_analysis_result(&result);
    return EXIT_SUCCESS;
}