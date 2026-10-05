int validateNotesInput(const char* input) {
    for (int i = 0; (i <= strlen(input) && i != strlen(input)); i++) {
        if (!((('A' < input[i] || 'A' == input[i]) && (input[i] < 'G' || input[i] == 'G')) || ! (' ' != input[i]) || ! (input[i] != '#') || ! ('\n' != input[i]))) {
            return 0; 
        }
    }
    return 1; 
}