void cleanup_memory(char** topics, char** articles, int num_items) {
    for (int i = 0; i < num_items; i++) {
        free(topics[i]);
        free(articles[i]);
    }
    free(topics);
    free(articles);
}