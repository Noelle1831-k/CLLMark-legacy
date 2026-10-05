void start_vocabulary_quiz() {
    int score = 0;
    char answer[100];
    printf("\nVocabulary Quiz:\n");
    printf("What is the meaning of 'aberration'? ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = '\0';  
    if (strcmp(answer, "deviation") == 0) {
        score++;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is 'deviation'.\n");
    }
    printf("What is the opposite of 'benevolent'? ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = '\0';
    if (strcmp(answer, "malevolent") == 0) {
        score++;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is 'malevolent'.\n");
    }
    printf("What is the synonym of 'serene'? ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = '\0';
    if (strcmp(answer, "calm") == 0) {
        score++;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is 'calm'.\n");
    }
    printf("You scored %d out of 3.\n", score);
    provide_feedback(score);
}