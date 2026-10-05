int main() {
    initializeDatabase();
    User user = createUser();
    int choice;
    do {
        printf("Welcome to WordQuizzer!\n");
        printf("1. Start Quiz\n2. View Progress\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                startQuiz(&user);
                break;
            case 2:
                viewProgress(&user);
                break;
            case 3:
                printf("Exiting WordQuizzer. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}