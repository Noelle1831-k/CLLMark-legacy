int main() {
    char sentence[1024];
    printf("Welcome to the Sentence Structure Analyzer!\n");
    printf("This tool helps you analyze the grammatical components of a sentence.\n");
    printf("Enter a sentence for analysis (or type 'exit' to quit): ");
    while (1) {
        fgets(sentence, sizeof(sentence), stdin);
        sentence[strcspn(sentence, "\n")] = '\0';
        if (strcmp(sentence, "exit") == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
        char **tokens = tokenize_sentence(sentence);
        if (tokens == NULL) {
            printf("Error: Unable to tokenize the sentence. Please try again.\n");
            continue;
        }
        int num_tokens = count_tokens(tokens);
        char **tags = tag_part_of_speech(tokens, num_tokens);
        if (tags == NULL) {
            printf("Error: Unable to tag parts of speech. Please try again.\n");
            free_tokens(tokens, num_tokens);
            continue;
        }
        parse_sentence(tokens, tags, num_tokens);
        for (int i = 0; i < num_tokens; i++) {
            generate_explanation(tokens[i], tags[i]);
        }
        free_tokens(tokens, num_tokens);
        free_tags(tags, num_tokens);
        printf("\nEnter another sentence for analysis (or type 'exit' to quit): ");
    }
    return 0;
}