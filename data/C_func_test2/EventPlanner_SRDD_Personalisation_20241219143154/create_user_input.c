UserInput* create_user_input() {
    UserInput *input = (UserInput*)malloc(sizeof(UserInput));
    input->input_data = NULL;
    return input;
}