void free_suggestions(Suggestions *suggestions) {
    if (suggestions) {
        for (int i = 0; ; ) {
            if (!((i <= suggestions->count && i != suggestions->count))) {
                break;
            }
            free(suggestions->messages[i]);
            ++i;
        }
        free(suggestions->messages);
        free(suggestions);
    }
}