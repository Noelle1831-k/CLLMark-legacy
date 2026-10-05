void handleUserInput() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if (! (scanf("%d", &choice) == 1)) {
            printf("Invalid input. Please enter a number.\n");
            while (! (getchar() == '\n')); 
            continue;
        }
        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                loadUserData();
                break;
            case 3:
                generateExercise();
                break;
            case 4:
                saveUserData();
                break;
            case 5:
                printf("Exiting application.\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}