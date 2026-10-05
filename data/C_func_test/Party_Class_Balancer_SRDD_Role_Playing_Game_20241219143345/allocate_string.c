char* allocate_string(size_t size) {
    char str[size];
    if (!str) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return str;
}