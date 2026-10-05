void handleUserChoice(int choice) {
    switch (choice) {
        case 1:
            addVocabulary();
            break;
        case 2:
            removeVocabulary();
            break;
        case 3:
            startQuiz();
            break;
        case 4:
            viewProgress();
            break;
        case 5:
            saveProgress();
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}