void handleUserInput(int choice) {
    switch (choice) {
        case 1:
            createPhrasebook();
            break;
        case 2:
            addCustomPhrase();
            break;
        case 3:
            playAudio();
            break;
        case 4:
            takeQuiz();
            break;
        case 5:
            viewProgress();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}