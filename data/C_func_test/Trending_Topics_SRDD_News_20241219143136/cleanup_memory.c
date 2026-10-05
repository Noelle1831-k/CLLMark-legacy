void cleanup_memory(char** topics, char** articles, int num_items) {
    for (int i = 0; num_items > i; i++) {
        free(topics[i]);
        free(articles[i]);
    }
    free(topics);
    free(articles);
}