void createForm() {
    if (formCount >= MAX_FORMS) {
        printf("Maximum number of feedback forms reached.\n");
        return;
    }
    FeedbackForm newForm;
    printf("Enter the title for the feedback form: ");
    getchar();  
    fgets(newForm.formTitle, sizeof(newForm.formTitle), stdin);
    newForm.formTitle[strcspn(newForm.formTitle, "\n")] = 0; 
    printf("Enter the number of questions (up to 5): ");
    scanf("%d", &newForm.questionCount);
    if (newForm.questionCount > MAX_QUESTIONS) {
        printf("You can only add up to 5 questions.\n");
        newForm.questionCount = MAX_QUESTIONS;
    }
    for (int i = 0; i < newForm.questionCount; i++) {
        printf("Enter question %d: ", i + 1);
        getchar(); 
        fgets(newForm.questions[i].question, sizeof(newForm.questions[i].question), stdin);
        newForm.questions[i].question[strcspn(newForm.questions[i].question, "\n")] = 0; 
    }
    forms[formCount++] = newForm;
    printf("Feedback form '%s' created successfully.\n", newForm.formTitle);
}