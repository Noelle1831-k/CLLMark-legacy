void deleteForm() {
    if (formCount == 0) {
        printf("No feedback forms available to delete.\n");
        return;
    }
    printf("Select a form to delete:\n");
    for (int i = 0; i < formCount; i++) {
        printf("%d. %s\n", i + 1, forms[i].formTitle);
    }
    int choice;
    printf("Enter form number: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > formCount) {
        printf("Invalid choice.\n");
        return;
    }
    for (int i = choice - 1; i < formCount - 1; i++) {
        forms[i] = forms[i + 1];
    }
    formCount--;
    printf("Feedback form deleted successfully.\n");
}