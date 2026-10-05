void run_quiz() {
    int score = 0;
    char answer[100];
    printf("\nQuiz Time!\n");
    printf("What is the capital of France? ");
    scanf("%s", answer);
    if (strcmp(answer, "Paris") == 0) {
        score++;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is 'Paris'.\n");
    }
    printf("What is 2 + 2? ");
    scanf("%s", answer);
    if (strcmp(answer, "4") == 0) {
        score++;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is '4'.\n");
    }
    printf("Your score is: %d\n", score);
    provide_feedback(score);
}