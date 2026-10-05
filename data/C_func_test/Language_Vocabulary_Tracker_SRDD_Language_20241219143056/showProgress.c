void showProgress() {
    printf("\nProgress Tracker:\n");
    printf("Total words learned: %d\n", getWordCount());
    int totalQuizzes = 10;  
    int correctAnswers = 40;  
    if (totalQuizzes > 0) {
        double accuracy = (correctAnswers / (double)(totalQuizzes * 5)) * 100;
        printf("Quiz Accuracy: %.2f%%\n", accuracy);
    }
}