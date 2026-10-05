void *allocateMemory(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        logError("Memory allocation failed.");
        exit(EXIT_FAILURE);
    }
    return ptr;
}