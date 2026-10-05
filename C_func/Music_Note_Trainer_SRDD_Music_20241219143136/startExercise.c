void startExercise() {
    int choice;
    displayMenu();
    choice = getUserInput();
    switch (choice) {
        case 1:
            generateNoteExercise();
            break;
        case 2:
            generateIntervalExercise();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}