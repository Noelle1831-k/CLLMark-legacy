int main(int argc, char *argv[]) {
    int choice;
    User *current_user = NULL;
    printf("Welcome to the Habit Tracker Application!\n");
    printf("Please choose an option:\n");
    printf("1. Add User\n");
    printf("2. Track Habit\n");
    printf("3. View Habit Progress\n");
    printf("4. Get Habit Recommendations\n");
    printf("5. Exit\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                current_user = add_user();
                break;
            case 2:
                if (current_user) {
                    track_habit(current_user);
                } else {
                    printf("No user found. Please add a user first.\n");
                }
                break;
            case 3:
                if (current_user) {
                    display_user_progress(current_user);
                } else {
                    printf("No user found. Please add a user first.\n");
                }
                break;
            case 4:
                if (current_user) {
                    generate_daily_recommendations(current_user);
                } else {
                    printf("No user found. Please add a user first.\n");
                }
                break;
            case 5:
                printf("Exiting the application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}