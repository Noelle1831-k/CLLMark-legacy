int detect_virus_signature(const char *filename) {
    printf("Checking file: %s for virus signatures...\n", filename);
    return strcmp(filename, "infected_file.txt") == 0 ? 1 : 0;
}