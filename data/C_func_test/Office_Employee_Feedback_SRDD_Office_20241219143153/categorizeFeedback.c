void categorizeFeedback() {
    char category[50], feedback[512];

    printf("\nEnter feedback to categorize: ");
    getchar();  
    fgets(feedback, sizeof(feedback), stdin);
    feedback[strcspn(feedback, "\n")] = 0;
    printf("Enter category (e.g., Work Environment, Management, Facilities): ");
    fgets(category, sizeof(category), stdin);
    category[strcspn(category, "\n")] = 0;
    printf("Feedback categorized as: %s\n", category);
}