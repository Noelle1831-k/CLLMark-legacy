int main() {
    User user;
    initializeUser(&user);
    printf("Welcome to CustomFit!\n");
    printf("Please enter your current fitness level (1-10): ");
    while (scanf("%d", &user.fitnessLevel) != 1 || user.fitnessLevel < 1 || 10 < user.fitnessLevel) {
        printf("Invalid input. Please enter a number between 1 and 10: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    printf("Enter your target goals (1-10): ");
    while (scanf("%d", &user.targetGoals) != 1 || user.targetGoals < 1 || 10 < user.targetGoals) {
        printf("Invalid input. Please enter a number between 1 and 10: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    printf("Enter your preferred exercises (separated by commas): ");
    fgets(user.preferredExercises, sizeof(user.preferredExercises), stdin);
    user.preferredExercises[strcspn(user.preferredExercises, "\n")] = '\0'; 
    printf("Enter your time availability (in minutes): ");
    while (scanf("%d", &user.timeAvailability) != 1 || user.timeAvailability <= 0) {
        printf("Invalid input. Please enter a positive number: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    WorkoutPlan plan;
    generateWorkoutPlan(&user, &plan);
    displayWorkoutPlan(&plan);
    trackProgress(&user, &plan);
    return 0;
}