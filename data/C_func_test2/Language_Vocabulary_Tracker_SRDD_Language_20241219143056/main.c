int main() {
    int choice;
    initializeVocabulary();
    while (1) {
        printf("\nLanguage Vocabulary Tracker\n");
        printf("1. Add New Word\n");
        printf("2. View Flashcards\n");
        printf("3. Take a Quiz\n");
        printf("4. View Progress\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        choice = getInputInt();
        switch (choice) {
            case 1:
                addNewWord();
                break;
            case 2:
                displayFlashcards();
                break;
            case 3:
                startQuiz();
                break;
            case 4:
                showProgress();
                break;
            case 5:
                printf("Exiting the application.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}