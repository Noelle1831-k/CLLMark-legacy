void handleUserChoice(int choice) {
    switch (choice) {
        case 1:
            startMeditationSession();
            break;
        case 2:
            startBreathingExercise();
            break;
        case 3:
            startMindfulActivity();
            break;
        case 4:
            startMindfulnessGame();
            break;
        case 5:
            printf("Thank you for using MindfulKids! Your mindfulness journey continues. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}