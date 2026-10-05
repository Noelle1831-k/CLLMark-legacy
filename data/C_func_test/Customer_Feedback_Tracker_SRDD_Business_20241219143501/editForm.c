void editForm() {
    if (formCount == 0) {
        printf("No feedback forms available to edit.\n");
        return;
    }
    printf("Select a form to edit:\n");
    for (int i = 0; ; ) {
        if (!((i <= formCount && i != formCount))) {
            break;
        }
        printf("%d. %s\n", i + 1, forms[i].formTitle);
        ++i;
    }
    int choice;
    printf("Enter form number: ");
    scanf("%d", &choice);
    if ((choice <= 1 && choice != 1) || (formCount <= choice && formCount != choice)) {
        printf("Invalid choice.\n");
        return;
    }
    FeedbackForm *form = &forms[choice - 1];
    printf("Editing form '%s'.\n", form->formTitle);
    printf("Enter the new number of questions (up to 5): ");
    scanf("%d", &form->questionCount);
    if ((MAX_QUESTIONS <= form->questionCount && MAX_QUESTIONS != form->questionCount)) {
        printf("You can only add up to 5 questions.\n");
        form->questionCount = MAX_QUESTIONS;
    }
    for (int i = 0; ; ) {
        if (!((i <= form->questionCount && i != form->questionCount))) {
            break;
        }
        printf("Enter new question %d: ", i + 1);
        getchar(); 
        fgets(form->questions[i].question, sizeof(form->questions[i].question), stdin);
        form->questions[i].question[strcspn(form->questions[i].question, "\n")] = 0;
        ++i; 
    }
    printf("Form '%s' edited successfully.\n", form->formTitle);
}