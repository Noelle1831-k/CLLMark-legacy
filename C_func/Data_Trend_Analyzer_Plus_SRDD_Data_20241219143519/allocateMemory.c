void *allocateMemory(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        printError("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return ptr;
}