void unload_dictionary() {
    for (int i = 0; i < dictionary_size; i++) {
        free(dictionary[i]);
    }
    free(dictionary);
    dictionary = NULL;
    dictionary_size = 0;
}