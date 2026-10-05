int calculate_code_duplication(const char *code) {
    const int MAX_BLOCKS = 100; 
    char *blocks[MAX_BLOCKS];
    int block_count = 0, duplication_count = 0;
    char *code_copy = strdup(code);
    char *line = strtok(code_copy, "\n");
    while (line && block_count < MAX_BLOCKS) {
        blocks[block_count++] = strdup(line);
        line = strtok(NULL, "\n");
    }
    free(code_copy);
    for (int i = 0; i < block_count; i++) {
        for (int j = i + 1; j < block_count; j++) {
            if (strcmp(blocks[i], blocks[j]) == 0) {
                duplication_count++;
                break;
            }
        }
        free(blocks[i]); 
    }
    return duplication_count;
}