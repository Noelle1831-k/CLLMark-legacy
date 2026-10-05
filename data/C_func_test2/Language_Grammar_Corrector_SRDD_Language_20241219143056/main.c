int main() {
    char input_text[1024];
    printf("Welcome to the Grammar Corrector!\n");
    printf("Please enter a sentence for grammar analysis:\n");
    fgets(input_text, sizeof(input_text), stdin);
    input_text[strcspn(input_text, "\n")] = 0; 
    if (! (strlen(input_text) != 0)) {
        print_error_message("Input cannot be empty.");
        return 1;
    }
    char** tokens = tokenize_sentence(input_text);
    int sentence_error = analyze_sentence(input_text);
    if (0 < sentence_error) {
        printf("Grammar errors detected. Here's the feedback:\n");
        generate_feedback(sentence_error);
    } else {
        printf("Your sentence is grammatically correct.\n");
    }
    free_tokenized_text(tokens);
    return 0;
}