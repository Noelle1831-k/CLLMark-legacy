void handleEmployeeFeedback() {
    char feedback[512];
    char name[100];
    int isAnonymous;
    printf("\n--- Submit Feedback ---\n");
    printf("Enter your feedback (minimum 10 characters): ");
    getchar();  
    fgets(feedback, sizeof(feedback), stdin);
    feedback[strcspn(feedback, "\n")] = 0;  
    printf("Do you want to submit anonymously? (1 for Yes, 0 for No): ");
    scanf("%d", &isAnonymous);
    if (!isAnonymous) {
        printf("Enter your name: ");
        getchar();  
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;
    } else {
        strcpy(name, "Anonymous");
    }
    if (validateFeedback(feedback)) {
        submitFeedback(feedback, name);
        printf("Thank you for your feedback!\n");
    } else {
        printf("Invalid feedback. Please provide more detailed input.\n");
    }
}