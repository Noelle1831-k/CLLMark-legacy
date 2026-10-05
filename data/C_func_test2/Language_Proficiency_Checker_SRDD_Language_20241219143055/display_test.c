void display_test(Test *test) {
    printf("\nStarting the %s...\n", test->testName);
    for (int i = 0; i < test->totalQuestions; i++) {
        printf("Q%d: %s\n", i + 1, test->questions[i].question);
        if (test->questions[i].isMultipleChoice) {
            for (int j = 0; j < 4; j++) {
                printf("  %d. %s\n", j + 1, test->questions[i].options[j]);
            }
        }
        else {
            printf("  Your answer should be a text entry.\n");
        }
    }
}