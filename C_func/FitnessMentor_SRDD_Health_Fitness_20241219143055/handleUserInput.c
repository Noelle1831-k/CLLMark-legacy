void handleUserInput() {
    int choice;
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                updateUser();
                break;
            case 3:
                deleteUser();
                break;
            case 4:
                addExercise();
                break;
            case 5:
                updateExercise();
                break;
            case 6:
                deleteExercise();
                break;
            case 7:
                generateWorkoutPlan();
                break;
            case 8:
                displayWorkoutPlan();
                break;
            case 9:
                trackProgress();
                break;
            case 10:
                saveData();
                break;
            case 0:
                saveData();
                printf("Exiting FitnessMentor. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}