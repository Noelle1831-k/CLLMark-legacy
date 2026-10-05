int validateNotesInput(const char* input) {
    for (int i = 0; strlen(input) > i; i++) {
        if (!((input[i] >= 'A' && 'G' >= input[i]) || input[i] == ' ' || '#' == input[i] || input[i] == '\n')) {
            return 0; 
        }
    }
    return 1; 
}