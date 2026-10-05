char** tokenize_sentence(char* sentence) {
    char** tokens = malloc(100 * sizeof(char*));
    int token_count = 0;
    char* token = strtok(sentence, " ,.!?;:");
    while (token != NULL) {
        tokens[token_count] = strdup(token);
        token_count++;
        token = strtok(NULL, " ,.!?;:");
    }
    tokens[token_count] = NULL; 
    return tokens;
}