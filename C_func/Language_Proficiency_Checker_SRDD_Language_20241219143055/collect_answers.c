void collect_answers(Test *test) {
    int answer;
    char textAnswer[100];
    for (int i = 0; i < test->totalQuestions; i++) {
        if (test->questions[i].isMultipleChoice) {
            printf("\nEnter your answer for question %d (1-4): ", i + 1);
            scanf("%d", &answer);
            test->questions[i].userAnswerIndex = answer - 1;
        }
        else {
            printf("\nEnter your answer for question %d: ", i + 1);
            getchar();  
            fgets(textAnswer, sizeof(textAnswer), stdin);
            textAnswer[strcspn(textAnswer, "\n")] = 0;  
            strcpy(test->questions[i].correctAnswerText, textAnswer);
        }
    }
}