void start_quiz() {
    printf("Starting quiz in %s at difficulty level %d...\n", selected_language, selected_difficulty);
    load_language_data(selected_language, selected_difficulty);
    int correct_answers = 0;
    for (int i = 0; i < 5; i++) {
        generate_question();
        char answer[50];
        printf("Your answer: ");
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = 0; 
        if (evaluate_answer(answer)) {
            correct_answers++;
            give_feedback(1); 
        } else {
            give_feedback(0); 
        }
    }
    printf("Quiz completed! You got %d out of 5 questions correct.\n", correct_answers);
}