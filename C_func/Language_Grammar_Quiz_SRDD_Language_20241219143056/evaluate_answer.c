int evaluate_answer(const char *user_answer) {
    if (strcmp(user_answer, "ran") == 0) {
        return 1;
    }
    return 0;
}