void generate_explanation(const char* word, const char* tag) {
    printf("\nExplanation for '%s' (%s):\n", word, tag);
    if (strcmp(tag, "NOUN") == 0) {
        printf("This is a noun, typically a person, place, or thing.\n");
        printf("Example: 'dog', 'city', 'happiness'.\n");
    } else if (strcmp(tag, "VERB") == 0) {
        printf("This is a verb, usually describing an action or state.\n");
        printf("Example: 'run', 'is', 'jumping'.\n");
    } else if (strcmp(tag, "ADJ") == 0) {
        printf("This is an adjective, modifying or describing a noun.\n");
        printf("Example: 'beautiful', 'quick', 'happy'.\n");
    } else if (strcmp(tag, "ADV") == 0) {
        printf("This is an adverb, modifying a verb, adjective, or another adverb.\n");
        printf("Example: 'quickly', 'very', 'happily'.\n");
    } else {
        printf("Unknown part of speech. Please consult a grammar guide.\n");
    }
}