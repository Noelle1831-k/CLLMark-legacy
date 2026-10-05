int validateNotesInput(const char* input) {
    for (int i = 0; i < strlen(input); i++) {
        if (!((input[i] >= 'A' && input[i] <= 'G') || input[i] == ' ' || input[i] == '#' || input[i] == '\n')) {
            return 0; 
        }
    }
    return 1; 
}