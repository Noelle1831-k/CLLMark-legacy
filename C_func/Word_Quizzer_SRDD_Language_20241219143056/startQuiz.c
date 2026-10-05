void startQuiz(User *user) {
    int language, difficulty;
    printf("Select Language (1-English, 2-Spanish): ");
    scanf("%d", &language);
    printf("Select Difficulty (1-Easy, 2-Medium, 3-Hard): ");
    scanf("%d", &difficulty);
    char *question = generateQuestion(language, difficulty);
    char *answer = getCorrectAnswer(question);
    printf("Question: %s\n", question);
    printf("Enter your answer: ");
    char userAnswer[100];
    scanf("%s", userAnswer);
    if (checkAnswer(userAnswer, answer)) {
        printf("Correct!\n");
        updateScore(user, 1);
    } else {
        printf("Incorrect. The correct answer was: %s\n", answer);
    }
}