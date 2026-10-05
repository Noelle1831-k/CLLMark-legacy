int validate_answer(const Question *question, char user_answer) {
    return user_answer == question->correct_option;
}