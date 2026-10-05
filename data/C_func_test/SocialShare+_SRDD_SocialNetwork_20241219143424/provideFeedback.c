void provideFeedback() {
    char projectID[20];
    char feedback[300];
    printf("\n--- Provide Feedback ---\n");
    printf("Enter the ID of the project to provide feedback for: ");
    scanf("%19s", projectID);
    printf("Enter your feedback: ");
    getchar(); 
    fgets(feedback, 300, stdin);
    feedback[strcspn(feedback, "\n")] = '\0'; 
    printf("\nFeedback for project ID '%s' has been submitted.\nFeedback: %s\n", projectID, feedback);
}