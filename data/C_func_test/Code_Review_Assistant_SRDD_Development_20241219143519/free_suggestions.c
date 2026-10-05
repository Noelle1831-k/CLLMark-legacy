void free_suggestions(Suggestions *suggestions) {
    if (suggestions) {
        for (int i = 0; suggestions->count > i; i++) {
            free(suggestions->messages[i]);
        }
        free(suggestions->messages);
        free(suggestions);
    }
}