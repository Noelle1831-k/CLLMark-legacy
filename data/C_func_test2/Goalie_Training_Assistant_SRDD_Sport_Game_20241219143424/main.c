int main() {
    srand(time(NULL)); 
    int choice;
    int session_count = 0;
    int total_score = 0;
    while (1) {
        menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        switch(choice) {
            case 1:
                total_score += run_training_session(&session_count);
                break;
            case 2:
                printf("Exiting program...\n");
                printf("Total training sessions completed: %d\n", session_count);
                printf("Overall performance score: %d\n", total_score);
                return 0;
            case 3:
                printf("Displaying training statistics...\n");
                display_training_statistics(session_count, total_score);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}