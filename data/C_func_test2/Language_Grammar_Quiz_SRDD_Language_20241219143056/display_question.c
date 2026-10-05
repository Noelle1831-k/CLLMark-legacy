void display_question(const char *question, const char *options[], int num_options) {
    printf("\nQuestion: %s\n", question);
    for (int i = 0; i < num_options; i++) {
        printf("%d. %s\n", i + 1, options[i]);
    }
}