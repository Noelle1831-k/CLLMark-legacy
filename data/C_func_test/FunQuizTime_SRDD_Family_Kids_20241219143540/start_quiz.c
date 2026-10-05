void start_quiz() {
    int score = 0, i;
    char user_answer;
    questions = load_questions(&question_count);
    if (questions == NULL) {
        printf("Error loading questions. Please check your data files.\n");
        return;
    }
    shuffle_questions(questions, question_count); 
    for (i = 0; i < question_count; i++) {
        display_question(&questions[i], i + 1);
        user_answer = get_user_answer();
        if (validate_answer(&questions[i], user_answer)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! Correct answer: %c\n", questions[i].correct_option);
        }
    }
    printf("Quiz Complete! Your score: %d/%d\n", score, question_count);
    save_score(score, question_count);
    free(questions);
}