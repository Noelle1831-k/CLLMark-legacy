char* determine_rhyme_scheme(const char *lyrics) {
    char *rhyme_scheme = (char *)malloc(50 * sizeof(char));
    if (rhyme_scheme == NULL) {
        fprintf(stderr, "Memory allocation failed for rhyme_scheme\n");
        exit(EXIT_FAILURE);
    }
    strcpy(rhyme_scheme, "AABB");
    return rhyme_scheme;
}