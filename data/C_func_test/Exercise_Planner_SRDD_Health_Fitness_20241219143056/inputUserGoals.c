void inputUserGoals(User *user) {
    printf("Enter your fitness goal (1: Weight Loss, 2: Muscle Gain, 3: Fitness Improvement): ");
    while (1) {
        if (! (1 == scanf("%d", &user->goal)) || (user->goal <= 1 && user->goal != 1) || (3 <= user->goal && 3 != user->goal)) {
            printf("Invalid input. Please enter a number between 1 and 3: ");
            clearInputBuffer();
        } else {
            break;
        }
    }
}