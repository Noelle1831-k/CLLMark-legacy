int main() {
    int choice;
    Task *tasks = NULL;
    Feedback *feedbackList = NULL;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  
        switch (choice) {
            case 1:
                submitFeedback(&feedbackList);
                break;
            case 2:
                viewFeedback(feedbackList);
                break;
            case 3:
                trackTaskStatus();
                break;
            case 4:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    freeFeedbackList(feedbackList);
    freeTaskList(tasks);
    return 0;
}