void takeQuiz() {
    srand(time(0));
    int score = 0;
    int totalQuestions = 5;
    char *questions[] = {"Translate 'Hello'", "Translate 'Goodbye'", "Translate 'Thank you'", "Translate 'Please'", "Translate 'Yes'"};
    char *answers[] = {"Hola", "Adiós", "Gracias", "Por favor", "Sí"};
    printf("Starting quiz...\n");
    for (int i = 0; i < totalQuestions; i++) {
        printf("%s: ", questions[i]);
        char userAnswer[50];
        scanf("%s", userAnswer);
        if (strcmp(userAnswer, answers[i]) == 0) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %s.\n", answers[i]);
        }
    }
    printf("Quiz completed. Your score: %d/%d\n", score, totalQuestions);
}