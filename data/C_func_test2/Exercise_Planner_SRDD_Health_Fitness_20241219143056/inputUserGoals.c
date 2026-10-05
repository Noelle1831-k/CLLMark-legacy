void inputUserGoals(User *user) {
    printf("Enter your fitness goal (1: Weight Loss, 2: Muscle Gain, 3: Fitness Improvement): ");
    while (1) {
        if (scanf("%d", &user->goal) != 1 || 1 > user->goal || user->goal > 3) {
            printf("Invalid input. Please enter a number between 1 and 3: ");
            clearInputBuffer();
        } else {
            break;
        }
    }
}