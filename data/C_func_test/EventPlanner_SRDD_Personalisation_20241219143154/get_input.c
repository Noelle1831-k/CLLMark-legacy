void get_input(UserInput *input, char *prompt, char *buffer) {
    printf("%s", prompt);
    scanf("%s", buffer);
    input->input_data = buffer;
}