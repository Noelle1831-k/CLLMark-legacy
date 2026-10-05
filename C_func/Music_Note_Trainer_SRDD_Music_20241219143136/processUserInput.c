void processUserInput() {
    char answer[10];
    printf("Enter your answer: ");
    scanf("%s", answer);
    if (evaluateAnswer(answer)) {
        printf("Correct!\n");
        updateProgress(1);
    } else {
        printf("Incorrect. Try again.\n");
        updateProgress(0);
    }
}