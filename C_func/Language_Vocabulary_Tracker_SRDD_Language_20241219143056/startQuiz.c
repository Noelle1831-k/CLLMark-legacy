void startQuiz() {
    if (getWordCount() == 0) {
        printf("No words available for quiz.\n");
        return;
    }
    srand(time(NULL));
    int score = 0;
    for (int i = 0; i < 5; i++) {
        int index = rand() % getWordCount();
        printf("What is the definition of the word '%s'? ", getWord(index));
        char answer[DEFINITION_LENGTH];
        fgets(answer, DEFINITION_LENGTH, stdin);
        answer[strcspn(answer, "\n")] = '\0';  
        if (strcmp(answer, getDefinition(index)) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct definition was: %s\n", getDefinition(index));
        }
    }
    printf("Quiz completed. Your score: %d/5\n", score);
}