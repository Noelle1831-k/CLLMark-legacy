int read_input_choice() {
    int choice;
    char *input = read_input();
    sscanf(input, "%d", &choice);
    free(input);
    return choice;
}