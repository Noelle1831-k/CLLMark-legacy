void processUserInput() {
    char *answer = (char*)malloc(sizeof(char) * 10);
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