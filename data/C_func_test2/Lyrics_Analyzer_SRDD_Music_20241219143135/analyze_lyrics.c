AnalysisResult analyze_lyrics(const char *lyrics) {
    AnalysisResult result;
    result.theme = determine_theme(lyrics);
    result.word_count = count_words(lyrics, result.words, result.frequencies);
    result.rhyme_scheme = determine_rhyme_scheme(lyrics);
    result.emotional_tone = determine_emotional_tone(lyrics);
    return result;
}