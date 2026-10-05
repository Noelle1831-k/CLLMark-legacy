void output_suggestions(Suggestions *suggestions) {
    if (!suggestions) {
        fprintf(stderr, "Error: Suggestions are NULL\n");
        return;
    }
    printf("Code Review Suggestions:\n");
    for (int i = 0; i < suggestions->count; i++) {
        printf("%s\n", suggestions->messages[i]);
    }
}