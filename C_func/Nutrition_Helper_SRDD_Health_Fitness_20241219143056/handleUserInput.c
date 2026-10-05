void handleUserInput() {
    char input[MAX_INPUT_LENGTH];
    int choice;
    while (1) {
        printf("Enter your choice: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        choice = atoi(input);
        switch (choice) {
            case 1:
                inputMeal();
                break;
            case 2:
                viewDailySummary();
                break;
            case 3:
                setNutritionalGoals();
                break;
            case 4:
                getRecommendations();
                break;
            case 5:
                printf("Exiting NutritionHelper. Goodbye!\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}