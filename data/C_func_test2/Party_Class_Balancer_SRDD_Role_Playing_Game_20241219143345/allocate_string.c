char* allocate_string(size_t size) {
    char* str = (char*)malloc(size * sizeof(char));
    if (!str) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return str;
}