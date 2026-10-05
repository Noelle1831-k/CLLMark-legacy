void free_user_input(UserInput *input) {
    free(input->input_data);
    free(input);
}