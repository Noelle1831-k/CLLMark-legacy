void startQuiz() {
    if (vocabularyCount == 0) {
        printf("No vocabulary available for quiz.\n");
        return;
    }
    srand(time(NULL));
    int score = 0;
    for (int i = 0; i < 5; i++) {
        int index = rand() % vocabularyCount;
        char answer[WORD_LENGTH];
        printf("What is the meaning of '%s'? ", vocabularyList[index].word);
        scanf("%s", answer);
        if (strcmp(answer, vocabularyList[index].meaning) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is '%s'.\n", vocabularyList[index].meaning);
        }
    }
    printf("Quiz completed. Your score: %d/5\n", score);
}