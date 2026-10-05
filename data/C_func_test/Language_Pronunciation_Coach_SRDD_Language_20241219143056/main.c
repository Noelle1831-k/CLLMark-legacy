int main() {
    printf("Welcome to the Pronunciation Improvement Software!\n");
    initializeExercises();
    while (1) {
        char choice;
        printf("Choose an option:\n1. Start Exercise\n2. Exit\n");
        scanf(" %c", &choice);
        if (choice == '1') {
            startExercise();
        } else if (choice == '2') {
            printf("Exiting the application. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}