void updateProgress(int correct) {
    if (correct) {
        correctAnswers++;
        printf("Progress updated: Correct answer.\n");
    } else {
        incorrectAnswers++;
        printf("Progress updated: Incorrect answer.\n");
    }
    printf("Correct Answers: %d, Incorrect Answers: %d\n", correctAnswers, incorrectAnswers);
}