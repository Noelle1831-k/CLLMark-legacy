int check_spelling(const char *input, const char *correct) {
    char lower_input[50], lower_correct[50];
    strcpy(lower_input, input);
    strcpy(lower_correct, correct);
    to_lowercase(lower_input);
    to_lowercase(lower_correct);
    return strcmp(lower_input, lower_correct) == 0;
}