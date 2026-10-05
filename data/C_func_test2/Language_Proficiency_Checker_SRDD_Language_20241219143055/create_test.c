Test *create_test(int testType) {
    Test *test = (Test *)malloc(sizeof(Test));
    if (test == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    switch (testType) {
        case 1:
            strcpy(test->testName, "Vocabulary Test");
            test->totalQuestions = 5;
            break;
        case 2:
            strcpy(test->testName, "Grammar Test");
            test->totalQuestions = 5;
            break;
        case 3:
            strcpy(test->testName, "Reading Comprehension Test");
            test->totalQuestions = 5;
            break;
        case 4:
            strcpy(test->testName, "Mixed Test");
            test->totalQuestions = 15; 
            break;
        default:
            strcpy(test->testName, "Unknown Test");
            test->totalQuestions = 0;
            break;
    }
    test->questions = (Question *)malloc(sizeof(Question) * test->totalQuestions);
    if (test->questions == NULL) {
        printf("Memory allocation for questions failed!\n");
        exit(1);
    }
    for (int i = 0; i < test->totalQuestions; i++) {
        sprintf(test->questions[i].question, "Sample Question %d", i + 1);
        for (int j = 0; j < 4; j++) {
            sprintf(test->questions[i].options[j], "Option %d", j + 1);
        }
        test->questions[i].correctAnswerIndex = i % 4;
        test->questions[i].isMultipleChoice = 1;  
    }
    return test;
}