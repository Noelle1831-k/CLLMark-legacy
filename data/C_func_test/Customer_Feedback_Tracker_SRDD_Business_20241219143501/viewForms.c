void viewForms() {
    if (formCount == 0) {
        printf("No feedback forms available.\n");
        return;
    }
    printf("Available feedback forms:\n");
    for (int i = 0; i < formCount; i++) {
        printf("%d. %s\n", i + 1, forms[i].formTitle);
        for (int j = 0; j < forms[i].questionCount; j++) {
            printf("  Question %d: %s\n", j + 1, forms[i].questions[j].question);
        }
    }
}