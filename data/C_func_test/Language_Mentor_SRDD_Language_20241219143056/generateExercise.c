void generateExercise() {
    printf("Generating a new exercise...\n");
    srand(time(0));
    int exerciseType = rand() % 3;
    switch (exerciseType) {
        case 0:
            printf("Translate the following sentence: 'Hello, how are you?'\n");
            break;
        case 1:
            printf("Fill in the blank: 'The cat is on the ____.'\n");
            break;
        case 2:
            printf("Conjugate the verb 'to be' in past tense.\n");
            break;
    }
    evaluateExercise();
}