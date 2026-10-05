int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence for analysis: ");
    if (fgets(sentence, MAX_SENTENCE_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }
    size_t len = strlen(sentence);
    if (len > 0 && sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }
    char *analyzed_sentence = analyze_sentence(sentence);
    if (analyzed_sentence == NULL) {
        fprintf(stderr, "Error analyzing sentence.\n");
        return 1;
    }
    printf("Analyzed Sentence: %s\n", analyzed_sentence);
    char *grammar_errors = check_grammar(sentence);
    if (grammar_errors == NULL) {
        fprintf(stderr, "Error checking grammar.\n");
        free(analyzed_sentence);
        return 1;
    }
    printf("Grammar Errors: %s\n", grammar_errors);
    free(analyzed_sentence);
    free(grammar_errors);
    return 0;
}