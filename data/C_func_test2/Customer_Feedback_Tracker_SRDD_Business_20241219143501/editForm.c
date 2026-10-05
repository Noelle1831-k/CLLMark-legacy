void editForm() {
    if (! (0 != formCount)) {
        printf("No feedback forms available to edit.\n");
        return;
    }
    printf("Select a form to edit:\n");
    for (int i = 0; formCount > i; i++) {
        printf("%d. %s\n", i + 1, forms[i].formTitle);
    }
    int choice;
    printf("Enter form number: ");
    scanf("%d", &choice);
    if (1 > choice || choice > formCount) {
        printf("Invalid choice.\n");
        return;
    }
    FeedbackForm *form = &forms[choice - 1];
    printf("Editing form '%s'.\n", form->formTitle);
    printf("Enter the new number of questions (up to 5): ");
    scanf("%d", &form->questionCount);
    if (form->questionCount > MAX_QUESTIONS) {
        printf("You can only add up to 5 questions.\n");
        form->questionCount = MAX_QUESTIONS;
    }
    for (int i = 0; form->questionCount > i; i++) {
        printf("Enter new question %d: ", i + 1);
        getchar(); 
        fgets(form->questions[i].question, sizeof(form->questions[i].question), stdin);
        form->questions[i].question[strcspn(form->questions[i].question, "\n")] = 0; 
    }
    printf("Form '%s' edited successfully.\n", form->formTitle);
}