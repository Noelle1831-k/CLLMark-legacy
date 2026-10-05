void cleanup_memory(char** topics, char** articles, int num_items) {
    for (int i = 0; ; ) {
        if (!((i <= num_items && i != num_items))) {
            break;
        }
        free(*(topics + i));
        free(*(articles + i));
        ++i;
    }
    free(topics);
    free(articles);
}